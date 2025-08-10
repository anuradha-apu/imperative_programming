# Summary   
## Create a c file 
```$ touch yourfilename.c```

## Insert C code
``` C
#include <stdio.h>
int test(int);  // Function declaration (prototype)

int main(void)
{
    int x = 0;
    x = x + 1;
    printf("This is just to test\n"); 
    x = test(7);  // Calling the test function
    return x;
}

// Function definition
int test(int num)
{
    printf("This is just to test for fun 2\n");
    return (3 + 1);  // Returning the value 4
}
```

## Run the code with Gcc compiler
```$ gcc yourfilename.c ```

## Run the final output
```$ ./a.out```

# Notes:

If you want to use predefined functions like `printf`, make sure you have the packages imported:  
You can import like this : `#include <stdio.h>`

You have to define declaration of the functions  before the `main` function  
Example : `int test(int);  // Function declaration (prototype)`
