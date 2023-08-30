// Kullanýcýnýn Girdiði Görüntüdeki Boþ Olan
// En Büyük Dörtgen Bölgenin Alanýný Bulur ve Bölgeyi Ýþaretler

/*
Örnek Girdi
1 0 0 0 0 0 1 0 0
0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0
1 0 0 0 1 0 0 1 0
0 0 1 0 0 1 0 0 1
0 0 0 0 0 0 1 0 0
0 0 0 0 1 0 0 0 0
0 1 0 0 0 0 0 1 0
*/

#include <stdio.h>

#define SATIR 10
#define SUTUN 9

main() {
    int dizi[SATIR][SUTUN], i, j, bi, bj;
    
    // Matrisi Oku
    for (i=0; i<SATIR; i++)
        for(j=0; j<SUTUN; j++)
            scanf("%d", &dizi[i][j]);
    
    int enBuyukAlan = 0, baslangic_i, baslangic_j, bitis_i, bitis_j;
    
    for (i=0; i<SATIR; i++) { // Sol Üst Köþenin Satýr Numarasý
        for (j=0; j<SUTUN; j++) { // Sol Üst Köþenin Sütun Numarasý
            int max_genislik = SUTUN-1;
            for (bi=i; bi<SATIR; bi++) {
                for (bj=j; bj<=max_genislik && dizi[bi][bj] == 0; bj++);
                max_genislik = bj-1;
                if (max_genislik < 0) break;
                int alan = (bi-i+1)*(bj-j);
                if (alan > enBuyukAlan) {
                    enBuyukAlan = alan;
                    baslangic_i = i; baslangic_j = j;
                    bitis_i = bi; bitis_j = bj;
                }
            }
        }
    }
    
    printf("\nEn Buyuk Bolgenin Alani: %d", enBuyukAlan);
    
    // Bölgeyi Ýþaretle
    for (i=0; i<SATIR; i++) {
        printf("\n");
        for(j=0; j<SUTUN; j++) {
            if (baslangic_i <= i && i <= bitis_i && baslangic_j <= j && j <= bitis_j)
                printf("* ");
            else
                printf("%d ",dizi[i][j]);
        }
    }
    getch();
}
