// Kullanýcýnýn Girdiði Görüntüde Kaç Adet Þekil Olduðunu Bulur

// Fetih Yöntemi:
// 1. 0 Olmayan Hücreleri Birbirinden Farklý Numaralandýr
// 2. 0 Olmayan Hücreler, Komþularýndan Büyükse Orayý Fethetsin (Orasý da Ayný Deðere Sahip Olsun)
// 3. Hiçbir fetih olmadýysa 4. adýma geç, yoksa 3. adýmý tekrarla
// 4. Bitti

/*
Örnek Girdiler: 
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
    
    // 0 Olmayan Her Hücreyi Numaralandýr
    int ulke_no = 1;
    for (i=0; i<SATIR; i++)
        for (j=0; j<SUTUN; j++)
            if (dizi[i][j] != 0) {
                dizi[i][j] = ulke_no;
                ulke_no++;
            }
    
    // Fetih Ýþlemleri
    while (1) {
        int fetih_yapildi_mi = 0;
        for (i=0; i<SATIR; i++)
            for (j=0; j<SUTUN; j++)
                if (dizi[i][j] != 0) {
                    int yonler[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
                    for (k=0; k<4; k++) {
                        int yeni_i = i + yonler[k][0];
                        int yeni_j = j + yonler[k][1];
                        if (yeni_i < 0 || yeni_i >= SATIR) continue; // Alan Dýþý
                        if (yeni_j < 0 || yeni_j >= SUTUN) continue; // Alan Dýþý
                        if (dizi[yeni_i][yeni_j] == 0) continue;     // Fethedilecek Ülke Yok (Deniz)
                        if (dizi[yeni_i][yeni_j] > dizi[i][j]) continue; // Rakip Daha Güçlü
                        if (dizi[yeni_i][yeni_j] == dizi[i][j]) continue; // Ayný Ülke Fethedilemez
                        dizi[yeni_i][yeni_j] = dizi[i][j]; // Fethet
                        fetih_yapildi_mi = 1;
                    }
                }
        if (fetih_yapildi_mi == 0)
            break;
    }
    
    // Matrisi Yazdýr
    for (i=0; i<SATIR; i++) {
        printf("\n");
        for (j=0; j<SUTUN; j++)
            printf("%3d ", dizi[i][j]);
    }
    
    // Matriste Kaç Adet Farklý Sayý Olduðu Saydýrýlarak Görselde
    // Kaç Adet Þekil Olduðu Bulunabilir
    
    getch();
}
