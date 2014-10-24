;;; gura-mode.el --- Gura major mode

;;; Copyright (C) 2014 ypsitau

;;(makunbound 'gura-mode-map)
;;(makunbound 'gura-mode-syntax-table)
;;(makunbound 'gura-font-lock-keywords)
;;(makunbound 'gura-imenu-generic-expression)
;;(makunbound 'gura-outline-regexp)

(defun gura-insert-brace-close () (interactive) (gura-insert-close-p ?\}))
(defun gura-insert-paren-close () (interactive) (gura-insert-close-p ?\)))
(defun gura-insert-bracket-close () (interactive) (gura-insert-close-p ?\]))

(defvar gura-mode-map
  (let ((map (make-sparse-keymap)))
	(define-key map "}" 'gura-insert-brace-close)
	(define-key map ")" 'gura-insert-paren-close)
	(define-key map "]" 'gura-insert-bracket-close)
	map)
  "Keymap for `gura-mode'.")

(defvar gura-mode-syntax-table
  (let ((st (make-syntax-table)))
	(modify-syntax-entry ?' "\"" st)
	(modify-syntax-entry ?_ "w" st)
	(modify-syntax-entry ?$ "w" st)
	;; comment syntax
	(modify-syntax-entry ?# "<" st)
	(modify-syntax-entry ?/ ". 124" st)
	(modify-syntax-entry ?* ". 23b" st)
	(modify-syntax-entry ?\n ">" st)
	st)
  "Syntax table for `gura-mode'.")

(defvar gura-font-lock-keywords
  `(
	;; function names for control sequence
	(,(rx symbol-start
		  (or
		   "if" "elsif" "else" "try" "catch" "finally" "raise"
		   "repeat" "while" "for" "cross" "break" "continue" "return"
		   "module" "class" "struct" "scope" "public" "private" "extern" "import"
		   "super" "this"
		   ) symbol-end)
	 (0 font-lock-keyword-face))
	;; constant variables
	(,(rx symbol-start
		  (or
		   "true" "false" "nil"
		   ) symbol-end)
	 (0 font-lock-constant-face))
	;; symbol name
	(,(rx "`" (1+ word))
	 (0 font-lock-variable-name-face))
	;; function name
	(,(rx symbol-start (group (1+ word)) (0+ space) "(")
	 (1 font-lock-function-name-face))
	;; module/class/instance name
	(,(rx symbol-start (group (1+ word)) (0+ space) ".")
	 (1 font-lock-variable-name-face))
	;; top-level assignment
	(,(rx line-start (group (1+ word)) (? ":" (1+ (or word ","))) (0+ space) "=")
	 (1 font-lock-variable-name-face)))
  "Keyword highlighting specification for `gura-mode'.")

(defvar gura-imenu-generic-expression
  )

(defvar gura-outline-regexp
  )

(define-derived-mode gura-mode fundamental-mode "Gura"
  "Major mode for editing Gura programming language."
  (set-syntax-table gura-mode-syntax-table)
  (use-local-map (nconc (make-sparse-keymap) gura-mode-map))
  (set (make-local-variable 'indent-line-function) 'gura-indent-line)
  (set (make-local-variable 'font-lock-defaults)
	   '(gura-font-lock-keywords nil nil nil nil)))

(defun gura-indent-line ()
  "Indent current line of Gura code."
  (interactive)
  (let ((savep (> (current-column) (current-indentation)))
		(indent (condition-case nil (max (gura-calculate-indentation) 0)
				  (error 0))))
	(if savep
		(save-excursion (indent-line-to indent))
	  (indent-line-to indent))))

(defvar gura-continued-line-offset default-tab-width
  "Offset at top of line continued after backslash.")

(defun gura-calculate-indentation ()
  "Return the column to which the current line should be indented."
  (interactive)
  (setq indent-offset 0)
  ;; Check if preceding lines end with a backslash
  (save-excursion
	(beginning-of-line)
	(let ((cont-flag (not (bobp))))
	  (while cont-flag
		(forward-line -1)
		(setq cont-flag (not (bobp)))
		(end-of-line)
		(if (eq (char-before) ?\\)
			(setq indent-offset gura-continued-line-offset)
		  (setq cont-flag nil)))))
  ;; Indentation for block
  (or
   (let* ((syntax (syntax-ppss (line-beginning-position)))
		  (pos-block-start (nth 1 syntax)) (pos-comment-or-string-start (nth 8 syntax)))
	 (or
	  (when pos-comment-or-string-start
		(let ((indent (current-indentation)))
		  (save-excursion
			(forward-line -1)
			(max indent (current-indentation))))) ;; inside comment or string
	  (when (and pos-block-start (eq (char-after pos-block-start) ?\())
		(save-excursion
		  (goto-char pos-block-start)
		  (end-of-line)
		  (if (eq (+ pos-block-start 1) (point))
			  (+ (current-indentation) (* 2 default-tab-width)) ;; no elements after parenthesis
			(progn
			  (goto-char pos-block-start)
			  (+ (current-column) 1))))))) ;; elements exist at the same line
   (save-excursion
	 (end-of-line)
	 (let ((ch (char-before)))
	   (unless (or (eq ch ?}) (eq ch ?])) (beginning-of-line)))
	 (let* ((line-cur (line-number-at-pos)) (pos-cur (point))
			(syntax (syntax-ppss)) (pos-block-start (nth 1 syntax)))
	   (if pos-block-start
		   (progn
			 (goto-char pos-block-start)
			 (or
			  (when (looking-at (rx "{" (0+ space) "|"))
				(save-excursion
				  (goto-char (match-end 0))
				  (let ((line-param-start (line-number-at-pos))
						(column-param-start (current-column)))
					(forward-sexp)
					(while (and (not (eq (char-before) ?|)) (< (point) pos-cur))
					  (forward-sexp))
					(when (and (not (eq line-cur line-param-start))
							   (<= line-cur (line-number-at-pos)))
					  column-param-start))))
			  (when (= line-cur (line-number-at-pos))
				(+ (current-indentation) indent-offset))
			  (progn
				(when (not (eq (current-column) 0))
				  (backward-sexp)
				  (when (eq (char-after) ?=)
					(backward-sexp)))
				(+ (current-indentation) default-tab-width indent-offset))))
		 indent-offset)))))

(defun gura-insert-close-p (ch)
  (insert-char ch 1)
  (save-excursion (gura-indent-line))
  (blink-matching-open))

(add-to-list 'auto-mode-alist '("\\.gura$" . gura-mode))
(add-to-list 'auto-mode-alist '("\\.guraw$" . gura-mode))

(provide 'gura-mode)
