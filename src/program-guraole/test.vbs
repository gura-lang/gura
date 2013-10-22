' cscript test.vbs
With CreateObject("ScriptControl")
	.Language = "Gura"
	.AddCode("add(a, b) = a + b")
	.ExecuteStatement "test = c + ('hello world ' + (1..10)).join(',')"
	'MsgBox .Eval("test")
	.Run "add", "hoge", "bb"
End With
