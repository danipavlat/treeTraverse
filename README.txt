Dani Pavlat     CMP SCI 4280
P0: Modified Binary Tree + Traversals

This program creates creates and traverses a modified binary tree,
using the value of the last letter of each data string.

## Build
	make

## Usage
	P0				reads from the keyboard until simulated EOF (CTRL + D)
	P0 < somefile	same as above but redirecting from somefile instead of keyboard
	P0 somefile		reads from somefile.sp2020

## Issues
The final usage option (reading directly from file specified as a command line argument)
does not work as intended, however the first two (stdin) options work as they should.

I am not sure what is going wrong here, but I imagine it will be a small logical error 
that I've yet to spot. I will resubmit when/if corrected.

## Changelog
commit ff524fb7ffe902db3d2b4a9f87730371603a8b53
Author: dpnqv <dpnqv@delmar.umsl.edu>
Date:   Mon Feb 14 20:07:06 2022 -0600

    renamed input file in tree.c for consistency with main.c

commit a472028b4d22703db68636be5ff6169c15db572c
Author: dpnqv <dpnqv@delmar.umsl.edu>
Date:   Sun Feb 13 17:11:13 2022 -0600

    updated file handling - works for iostream options

commit aa76d2a5bd30f528836461eb4dc16e3008dbe77c
Author: dpnqv <dpnqv@delmar.umsl.edu>
Date:   Sun Feb 13 14:13:30 2022 -0600

    more file i/o progress

commit 8edc7dbee2f74cf94bf506192b01de5872f0f15a
Author: dpnqv <dpnqv@delmar.umsl.edu>
Date:   Sun Feb 13 13:56:38 2022 -0600

    wip file validation and i/o operations

commit 36af280dcb134dc1f336674b90ee2d34065ad70b
Author: dpnqv <dpnqv@delmar.umsl.edu>
Date:   Wed Feb 9 21:44:04 2022 -0600

    corrected newNode function

commit 9ac6ed6eb7acf396049a7ea57408d72cbdb06d02
Author: dpnqv <dpnqv@delmar.umsl.edu>
Date:   Sun Feb 6 17:04:10 2022 -0600

    wip buildTree + printPreorder: output is closer but not 100%

commit 4f47f0f96e58d0834c058f9f87a018e181c106f8
Author: dpnqv <dpnqv@delmar.umsl.edu>
Date:   Sat Feb 5 20:33:10 2022 -0600

    added buildTree function

commit cce07cad1aa068fdf71a9e584dd724ea964b7c0f
Author: dpnqv <dpnqv@delmar.umsl.edu>
Date:   Sat Feb 5 13:47:50 2022 -0600

    initial commit
