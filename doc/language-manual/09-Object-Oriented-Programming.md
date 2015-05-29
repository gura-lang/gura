# Object Oriented Programming


## Class and Instance

A **class** is a kind of environment that contains properties such as functions and variables,
and has an ability to create **instances** that share these properties.
A class is associated with a data type one by one,
which means that all the values in a script are bound to certain classes.
For example, a value `3.14` is associated with `number` class,
and `'hello world'` with `string` class.

A class contains functions called **method** that operate with a class or an instance.
A method that belongs to a class is called **class method** and is described as below,
where `Foo` and `func` are names of the class and the class method respectively.

    Foo.func()

A method that works on an instance is called **instance method** and is described as below,
where `Foo` and `func` are names of the class and the instance method respectively.

    Foo#func()

The symbol `#` is not used for an actual instance operation
and only appears in documentation to describe instance methods.
You can call an instance method like below, where `foo` is an instance of class `Foo`.

    foo.func()

A class also owns variables called  **class variable**,
which are shared by instances from the class.
Each instance can contain its own variables that are called **instance variable**.

A class variable is described as below,
where `Foo` and `value` are names of the class the class variable respectively:

    Foo.value

An instance variable is described as below,
where `Foo` and `value` are names of the class the instance variable respectively:

    Foo#value

You can use `dir()` function to see what methods and variables are available with a value.

    >>> x = 3.14
    3.14
    >>> dir(x)
    [`__call__, `__iter__, `clone, `getprop!, `is, `isinstance, `isnil, `istype, `nomap, `roundoff, `setprop!, `tonumber, `tostring]


## User-defined Class

You can use `class` function to create a user-defined class.
The code below creates a class named `A` with empty properties.

    A = class {}

This assignment would create a class named `A`
and also define a constructor function `A()` that generates an instance of the class.
You can call the constructor function like below:

    a = A()

A block of the `class` function should contain Assign and Caller expressions.
Existance of other expressions would cause an error.
They're evaluated just one time when the class is created.
Actual jobs in these expressions are summarized below:

* **Assign expression**

  A function assigned in the block becomes a method that belong to the class.
  If the function is declared with `:static` attribute appended right after the argument list,
  it would become a class method that you can call along with the class name.
  Otherwise, it would become an instance method that works with an instance
  created from the class.

  A variable assigned in the block are registered as a class variable
  that belong to the class itself, not to an instance.

  The assigned value is actually evaluated at the timing of assignment,
  which means you can even call a function to get the value.

* **Caller expression**

  A function or another callable is evaluated within the class as its environment.

Here's a sample script to see details about factors in the block.

    Person = class {
        
        __init__(name:string, age:number, role:string) = {
            this.name = name
            this.age = age
            this.role = role
        }
        
        fmt = 'name: %s, age: %d, role:%s\n'  // class variable
        
        Print() =  {
            // A class variable doesn't need 'this' or class name when accessing it
            // while an instance variable does.
            printf(fmt, this.name, this.age, this.role)
        }
        
        Test():static = {
            println('test of class method')
        }
        
    }

In an instance method, a variable named `this` is defined,
which contains a reference to the instance itself.
You always need to specify `this` variable to access instance variables and instance methods.

As for a class variable, a method can refer to it without specifying `this` or the class name.

An instance method `__init__()` is a special one that defines a constructor function.
Its arguments are reflected on that of the constructor.
The sample above creates a function named `Person` that has a declaration shown below:

    Person(name:string, age:number, role:string) {block?}

You can create an instance by calling it like below:

    p = Person('Taro Yamada', 27, 'engineer')

If you specify an optional block, the block procedure will be evaluated
with a block parameter that takes the created instance.

    Person('Taro Yamada', 27, 'engineer') {|p|
        // any process
    }

After an instance is created, you can call an instance method with it.
Below is an example to call an instance method `Print()`,
where `p` is the created instance:

    p.Print()

You can call a class method `Test()` like below:

    Person.Test()

You can also call a class method by specifying an instance.

    p.Test()



## Inheritance

### Basic

You can create an inherited class by specifying a super class in an argument of `class()`.

    Person2 = class(Person) {
        // class variable and methods
    }

If you don't declare `__init__()` method in the derived class, it would inherit a constructor of the super class.


### Constructor in Derived Class

When you declare `__init__()` method in the derived class,
you have to specify block parameters that satisfies the argument declaration of the super class's constructor.

    Teacher = class(Person) {
        __init__(name:string, age:number) = {|name, age, 'teacher'|
        }
        Work() = {
            println('give lectures to others')
        }
    }

    Student = class(Person) {
        __init__(name:string, age:number) = {|name, age, 'student'|
        }
        Work() = {
            println('learn about something')
        }
    }

As block parameters are just like oridinary arguments in a function call,
you can describe any expressions in them.
Though, take notice that you have to surround an expression including bitwise OR operation "`|`"
with parentheses to avoid it from being confused with border characters around block parameters.
See the example below:

    A = class {
        __init__(name:string, bitflags:number) = {
            // any jobs
        }
    }

    B = class(A) {
        __init__() = {|'hello', (1 | 4 | 8)|
            // any jobs
        }
    }


### Method Override

Take a look at a behavior of instance methods in an inherited class.
Consider the following script:

    A = class {
        func() = {
            println('A.func()')
        }
    }

    B = class(A) {
        func() = {
            println('B.func()')
        }
        test() = {
            this.func()  // calls B#func()
        }
    }

    b = B()
    b.test()

Both class A and B have a method with the same name `func()`.
When the method `B#test()` evaluates `this.func()`, it actually calls `B#func()`.

You can use `super()` function to call a method that belongs to a super class.
Below is a sample code to show how to use it.

    B = class(A) {
        func() = {
            println('B.func()')
        }
        test() = {
            super(this).func()  // calls A#func()
        }
    }


## Encapsulation

By default, instance and class variables are only accessible through `this` variable.
Such variables are called **private variable**.
You can make them accessible through other instance variables
by specifying `:public` attribute in their assignment expressions.
Those variables are called **public variable**.

    X = class {
        
        c = 3
        d:public = 4
        
        __init__() = {
            this.a = 1
            this.b:public = 2
        }
    }

    x = X()
    println(x.a)    // private instance variable .. Error
    println(x.b)    // public instance variable  .. OK
    println(x.c)    // private class variable    .. Error
    println(x.d)    // public class variable     .. OK

You can also call `public()` function within a block of `class()` function
that indicates which variables are to be publicized.
The `public()` function takes a block that contains two types of expressions: Identifier and Assign.
An Identifer expression only declares a variable symbol for publication.
An Assign expression creates a public class variable with the specified value.

The script below is equivalent with the above but uses `public()` function.

    X = class {
        
        c = 3
        public {
            b
            d = 4
        }
        __init__() = {
            this.a = 1
            this.b = 2
        }
    }

Different from variables, methods are accessible through variables other than `this` by default.
Such methods are called **public method**.
You can make them only accessible through `this` variable
by specifying `:private` attribute in their assignment expressions.
Those methods are called **private method**.


## Structure

A structure is a kind of a class, but offers a simple way to implement a constructor.
Function `struct` takes variable declarations as its arguments that are reflected on the generated constructor.
Below is an example:

    Point = struct(x:number, y:number)

This generates a constructor shown below:

    Point(x:number, y:number)

You can call it like below:

    pt = Point(3, 4)

A created instance from this class will have members named `x` and `y`.

    printf('%d, %d\n', pt.x, pt.y)

The code above that uses `struct` can be written using `class` like below:

    Point = class {
        __init__(x:number, y:number) = {
            this.x:public = x
            this.y:public = y
        }
    }

A structure can also have methods by describing them in a block of `struct` function.

    Point = struct(x:number, y:number) {
        Move(xdiff:number, ydiff:number) = {
            this.x += xdiff
            this.y += ydiff
        }
        Print() = {
            printf('%d, %d\n', this.x, this.y)
        }
    }


## Creation of Multiple Instances

How can we create a list of instances from a certain class?
Below is an example to create a list of `Person` instances.

    people = [
        Person('Kikuo Ochiai',     24, 'teacher')
        Person('Seiji Miki',       33, 'engineer')
        Person('Haruka Nakao',     28, 'sales')
        Person('Takashi Sugimura', 21, 'student')
    ]

Obviously, it's cumbersome to describe a function name `Person()` for each item.
Using a list creation function `@` enables you to write more simple code.

    people = @(Person) {
        { 'Kikuo Ochiai',     24, 'teacher'  }
        { 'Seiji Miki',       33, 'engineer' }
        { 'Haruka Nakao',     28, 'sales'    }
        { 'Takashi Sugimura', 21, 'student'  }
    }

Function `@` takes a function such as a constructor,
and its block contains a set of argument lists fed into that function.
