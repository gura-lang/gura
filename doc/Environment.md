---
layout: page
lang: en
title: Environment
chapter: 5
---

# {{ page.chapter }}. {{ page.title }}

## {{ page.chapter }}.1. Overview

Environment is a container to store
maps associating symbols and values and maps associating symbols and value types.

Module, Class, and Object are all inherited from Environment.

scope problems

    x = 0
    if (true) {
        x = 3
    }
    println(x)

## {{ page.chapter }}.2. Frame

Frame contains:

* value map
* value type map

Frame stack

Frame cache




Environment type:

* root
* local
* block
* class
* object
* lister

When the Interpreter starts, it runs with an Environment containing a frame of `root` type.

    +-------------------+
    |       root        |
    +-------------------+

In a function call, the Interpreter creates a new Environment with cloned frames
and pushes a new frame of `local` type.

    +-------------------+
    |      local        |
    +-------------------+
    |       root        |
    +-------------------+

When a block is evaluated, the Interpreter creates a new Environment with cloned frames
and pushes a frame of `block` type.

    +-------------------+
    |      block        |
    +-------------------+
    |       root        |
    +-------------------+



    +-------------------+
    |      block        |
    +-------------------+
    |      local        |
    +-------------------+
    |      local        |
    +-------------------+
    |       root        |
    +-------------------+


    +-------------------+
    |      class        |
    +-------------------+
    |       root        |
    +-------------------+


    +-------------------+
    |      object       |
    +-------------------+
    |      class        |
    +-------------------+
    |       root        |
    +-------------------+
