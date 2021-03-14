# Enigma

This is my attempt at creating the [Enigma Machine](https://en.wikipedia.org/wiki/Enigma_machine) used by the Germans in WW2 to encrypt messages.

Rotor configurations can be found [here](https://www.codesandciphers.org.uk/enigma/rotorspec.htm).

## Goals

* To become more familiar with the C++ Programming Language
* Stick to a TDD lifecycle
* Learn how to use CMake
* Create an Enigma Machine

The following are nice to haves but are not the main goals of this project

* See how this can be turned into a unix command line tool to encrypt files (like `openssl`)
* Try to break the Enigma Code

## Features

* Interact through a command line interface
* Can input either files or type message
* Output to a file or terminal
* Machine should be configurable using JSON (or some other structured file format)
* Inputting encrypted text into a machine with the same configuration should result in the plain text being returned
