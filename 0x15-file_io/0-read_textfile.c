include "main.h"


/**
read_textfile - function that reads a text
file and should prints it to the POSIX standard output
@filename: the file name
@letters: the number of letters
Return: actual number of letters or 0 if falls
**/

ssize_t read_textfile(const char *filename, size_t letters) {
    if (filename == NULL) {
        return 0;
    }
    
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return 0;
    }
    
    char *buffer = (char *) malloc(sizeof(char) * (letters + 1));
    if (buffer == NULL) {
        close(fd);
        return 0;
    }
    
    ssize_t bytes_read = read(fd, buffer, letters);
    if (bytes_read == -1) {
        close(fd);
        free(buffer);
        return 0;
    }
    
    ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    if (bytes_written == -1 || bytes_written != bytes_read) {
        close(fd);
        free(buffer);
        return 0;
    }
    
    close(fd);
    free(buffer);
    return bytes_read;
}
