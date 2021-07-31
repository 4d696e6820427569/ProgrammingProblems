/**
 * EPI Chapter 09 Stack And Queues
 *
 * 07/10/2021
 *
 * Normalize Pathnames
 *
 * A file or directoy can be specified via a string called the pathname.
 * This string may specify an absolute path, starting from the root, e.g.,
 * /usr/bin/gcc, or a path relative to the current working directory, e.g.,
 * scripts/awkscripts.
 *
 * The same directory may be specified by multiple directory paths. For
 * example, /usr/lib/../bin/gcc and scripts//./../scripts/awkscripts/././
 * specify equivalent absolute and relative pathnames.
 *
 * Write a program which takes a pathname, and returns the shortest equivalent
 * pathname. Assume individual directories and files have names that use only
 * alphanumeric characters. Subdirectory names may be combined using forward
 * slashes (/), the current directory (.), and parent directory (..).
 *
 * Hint: Trace the cases. How should . and .. be handled? Watch for invalid
 * paths.
 */


