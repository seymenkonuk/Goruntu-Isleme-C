// Kullan�c�n�n Girdi�i G�r�nt�de Ka� Adet �ekil Oldu�unu Bulur

// Fetih Y�ntemi:
// 1. 0 Olmayan H�creleri Birbirinden Farkl� Numaraland�r
// 2. 0 Olmayan H�creler, Kom�ular�ndan B�y�kse Oray� Fethetsin (Oras� da Ayn� De�ere Sahip Olsun)
// 3. Hi�bir fetih olmad�ysa 4. ad�ma ge�, yoksa 3. ad�m� tekrarla
// 4. Bitti

/*
�rnek Girdiler: 
0 0 0 0 0 0 0 0 0 0
1 1 1 0 0 0 1 1 1 0
0 1 0 0 1 0 1 1 1 0
1 1 0 1 1 0 0 0 1 0
0 0 1 1 1 1 1 0 1 0
0 0 0 0 1 1 0 0 1 0
0 0 0 0 1 0 0 0 1 0
0 1 1 0 1 0 0 0 1 0
0 1 1 1 1 1 0 0 1 0
0 1 1 1 1 1 0 0 1 0

0 1 1 0 0 1 1 0 0 1
0 1 1 0 0 0 0 0 0 1
0 1 1 0 1 1 1 0 0 1
1 0 0 0 1 1 1 0 0 1
1 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1 0
0 1 1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0
0 0 1 1 1 1 0 0 0 1

*/

#include <stdio.h>

#define SATIR 10
#define SUTUN 10

main() {
    int dizi[SATIR][SUTUN], i, j, k;
    
    // Matrisi Oku
    for (i=0; i<SATIR; i++)
        for (j=0; j<SUTUN; j++)
            scanf("%d", &dizi[i][j]);
    
    // 0 Olmayan Her H�creyi Numaraland�r
    int ulke_no = 1;
    for (i=0; i<SATIR; i++)
        for (j=0; j<SUTUN; j++)
            if (dizi[i][j] != 0) {
                dizi[i][j] = ulke_no;
                ulke_no++;
            }
    
    // Fetih ��lemleri
    while (1) {
        int fetih_yapildi_mi = 0;
        for (i=0; i<SATIR; i++)
            for (j=0; j<SUTUN; j++)
                if (dizi[i][j] != 0) {
                    int yonler[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
                    for (k=0; k<4; k++) {
                        int yeni_i = i + yonler[k][0];
                        int yeni_j = j + yonler[k][1];
                        if (yeni_i < 0 || yeni_i >= SATIR) continue; // Alan D���
                        if (yeni_j < 0 || yeni_j >= SUTUN) continue; // Alan D���
                        if (dizi[yeni_i][yeni_j] == 0) continue;     // Fethedilecek �lke Yok (Deniz)
                        if (dizi[yeni_i][yeni_j] > dizi[i][j]) continue; // Rakip Daha G��l�
                        if (dizi[yeni_i][yeni_j] == dizi[i][j]) continue; // Ayn� �lke Fethedilemez
                        dizi[yeni_i][yeni_j] = dizi[i][j]; // Fethet
                        fetih_yapildi_mi = 1;
                    }
                }
        if (fetih_yapildi_mi == 0)
            break;
    }
    
    // Matrisi Yazd�r
    for (i=0; i<SATIR; i++) {
        printf("\n");
        for (j=0; j<SUTUN; j++)
            printf("%3d ", dizi[i][j]);
    }
    
    // Matriste Ka� Adet Farkl� Say� Oldu�u Sayd�r�larak G�rselde
    // Ka� Adet �ekil Oldu�u Bulunabilir
    
    getch();
}
