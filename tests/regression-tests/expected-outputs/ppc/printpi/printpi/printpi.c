int main(int argc, union { char *[] *; double; } argv);

/** address: 0x10000418 */
int main(int argc, union { char *[] *; double; } argv)
{
    printf("Pi is about %.5f\n", argv);
    return 0;
}

