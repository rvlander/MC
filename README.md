MC
==

OVERVIEW
________

MC is a prototype, a proof of concept that MATLAB code can be converted to another programming language automatically. Currently, only Java as a target language is supported.

MC was written in the context of my PhD as I needed to quickly translate MATLAB code to Java code without using MATLAB JA Builder. The latter generates Java libraries, slowly, that need the (big) MRC to be installed on each station on which the translated code is running. This is why I started MC : being able to get pure Java code from MATLAB files.

The code provided is drafty and needs to be tidy up and refactored. More language could also be supported. I would be interested in driving this tasks but I need time and money for that. Any support is welcome.

However, MC currently meets my needs and was able to translate a sub-domain of the MATLAB  language to Java correctly. If ever you need such a translator, please test MC and give me some feedback it might motivate me to follow the work. 


CLONE AND RUN
_____________

Requirements:

MC was developed under Linux using C/C++, Flex, Bison and bash scripts. You will need all the associated packages to compile and run it.

Earlier revisions of MC also supported Windows via cygwin (at least for compilation). Tests needs to be performed to know if it is still the case.

Configure:

  1. Modify mc.y line 1036-1038 to make it match your configuration.

Compile and Run:

  1. You'd better be in the MC directory.
  2. Just execute the launch.sh script passing the file you want to translate as an argument. If no argument is passed the default exemple/test.m is launched. As it is the test on which we are currently developping to add more support to MC, errors might occur. However, MC might work on your matlab code provided that it (or its dependancies) use only the subdomain of MATLAB supported by MC.

SUPPORTED MATLAB FEATURES
_________________________

  * All (?) langage basics and operators
  * Up to 2 dimension matrices
  * function calls
  * ... TODO : be more specific

TODO
____

  1. Rework the code (to make it clean and tidy)
  2. Add support for more MATLAB features
  3. Add support for more target languages

AUTHOR
______

Gaëtan André <gaetan.andre@gmail.com>  
