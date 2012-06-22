#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <unistd.h>    /* for getopt */
#include "compiler.h"

int main (int argc, char **argv) {
    int c;

    char * source =0;
    char * output_dir =0;
    char * header = 0;
    while ( (c = getopt(argc, argv, "o:h:")) != -1) {
        int this_option_optind = optind ? optind : 1;
        switch (c) {
        case 'o':
            printf ("option o with value '%s'\n", optarg);
            output_dir = optarg;
            break;
        case 'h':
            printf ("option h with value '%s'\n", optarg);
            header = optarg;
            break;
        case '?':
            break;
        default:
            printf ("?? getopt returned character code 0%o ??\n", c);
        }
    }
    if (optind < argc) {
        source = argv[optind++];
        /*printf ("non-option ARGV-elements: ");
        while (optind < argc)
            printf ("%s ", argv[optind++]);
        printf ("\n");*/
    }
    
    compile(source,output_dir,header);
    
    exit (0);
}