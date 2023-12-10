//
//  main.c
//  ArdaYigit-1230505022
//
//  Created by Arda Yiğit on 10.12.2023.
//
#include <stdio.h>
#include <string.h>

int main(void) {
    char metin[100];
    int anahtar, i;

    // Kullanıcıdan metni al
    printf("Metni girin: ");
    fgets(metin, sizeof(metin), stdin);

    // Kullanıcıdan şifreyi al (26'dan büyükse modunu al)
    printf("Şifreyi girin: ");
    scanf("%d", &anahtar);
    anahtar = anahtar % 26;

    int uzunluk = strlen(metin);

    // Metni şifrele
    for (i = 0; i < uzunluk; ++i) {
        // Boşluk karakterlerini şifreleme işlemi dışında tut
        if (metin[i] != ' ' && metin[i] != '\n') {
            metin[i] = metin[i] + anahtar;

            // Eğer şifrelenmiş karakter 'Z'yi aşarsa veya 'z'yi aşarsa döngüyle başa dön
            if ((metin[i] > 'Z' && metin[i] < 'a') || metin[i] > 'z') {
                metin[i] = metin[i] - 26;
            }
        }
    }

    // Şifrelenmiş metni yazdır
    printf("Şifrelenmiş metin: %s\n", metin);

    return 0;
}
