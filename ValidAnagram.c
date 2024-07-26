#define max_ascii_chars 256

bool isAnagram(char* s, char* t) {

    int ascii[max_ascii_chars] = {0};

    while (*s != '\0') {
        ascii[*s] += 1;
        s++;
    }

    while (*t != '\0') {
        ascii[*t] -= 1;
        t++;
    }

    for (int i = 0; i < max_ascii_chars; i++) {
        if (ascii[i] != 0) {
            return false;
        }
    }
    return true;
}
