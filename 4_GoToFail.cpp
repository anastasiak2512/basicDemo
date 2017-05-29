//
// Created by AK on 30/10/16.
//

int gotofail(int x) {
    if (x == 10)
        return 7;
    if (x == 8)
        goto fail;
        goto fail;
    if (x == 7)
        return 8;
    fail:
    return 0;
}