/**
 * @file main.c
 *
 * Main program.
 *
 * Copyright (c) 2017 Richard Senior
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/// @cond Doxygen_Suppress
#define _POSIX_C_SOURCE 200809L
/// @endcond

#include "main.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Prints a usage message to standard output.
 */
static void usage()
{
    printf("hello v%s\n", PROJECT_VERSION);
    puts("Usage: hello [OPTIONS]");
    puts("  -n, --name   Name used in greeting");
}

/**
 * Main program.
 *
 * @param argc number of arguments
 * @param argv program arguments
 * @return exit status
 */
int main(int argc, char **argv)
{
    static struct option longopts[] = {
        {"name", required_argument, NULL, 'n'},
        {NULL, 0, NULL, 0}
    };

    int c;
    char *name = NULL;
    while ((c = getopt_long(argc, argv, "n:", longopts, NULL)) != -1) {
        switch (c) {
        case 'n':
            if ((name = strdup(optarg)) == NULL) {
                perror("strdup");
                exit(EXIT_FAILURE);
            }
            break;
        default:
            usage();
            exit(EXIT_FAILURE);
            break;
        }
    }

    printf("Hello %s!\n", name != NULL ? name : "World");
    free(name);
    return EXIT_SUCCESS;
}
