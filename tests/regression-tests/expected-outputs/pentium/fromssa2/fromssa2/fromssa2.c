int main(int argc, char *argv[]);

/** address: 0x08048328 */
int main(int argc, char *argv[])
{
    int ebx; 		// r27
    int ebx_1; 		// r27{0}
    int ebx_4; 		// r27{0}
    int local3; 		// ebx_1{0}

    ebx = 0;
    local3 = ebx;
    do {
        ebx_1 = local3;
        ebx_4 = ebx_1 + 1;
        printf("%d ", ebx_1 + 1);
        local3 = ebx_4;
    } while (ebx_1 + 1 <= 9);
    printf("a is %d, x is %d\n", 10, 10);
    return 0;
}
