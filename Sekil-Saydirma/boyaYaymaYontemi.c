// Kullanýcýnýn Girdiði Görüntüde Kaç Adet Þekil Olduðunu Bulur

// Boya Yayma Yöntemi:
// 1. 1 ile Karþýlaþtýðýnda Oraya Boya Damlat (Kaçýncý Þekil Olduðu Numarasýný Ver (Negatif Olarak))
// 2. 1 ile Karþýlaþmadýysan 5. adýma git
// 3. Boyayý Yayabildiðin Kadar Yay (O Sayýyla Temas Eden Hücreler O Sayýya Eþitlensin)
// 4. 1. Adýma Dön
// 5. Bitti

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
    int dizi[SATIR][SUTUN], i, j, k, m, yon;
    
    // Matrisi Oku
    for (i=0; i<SATIR; i++)
        for (j=0; j<SUTUN; j++)
            scanf("%d", &dizi[i][j]);
    
    // Þekilleri Say
    int boya_no = 0;
    for (i=0; i<SATIR; i++) {
        for (j=0; j<SUTUN; j++) {
            if (dizi[i][j] == 1) {
                boya_no--;
                dizi[i][j] = boya_no; // Boyayý Damlat
                // Boyayý Yay
                while (1) {
                    int yayilmaBittiMi = 1;
                    for (k=0; k<SATIR; k++) {
                        for (m=0; m<SUTUN; m++) {
                            if (dizi[k][m] == boya_no) {
                                int yonler[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
                                for (yon=0; yon<4; yon++) {
                                    int yeni_i = k + yonler[yon][0];
                                    int yeni_j = m + yonler[yon][1];
                                    if (yeni_i < 0 || yeni_i >= SATIR) continue; // Alan Dýþý
                                    if (yeni_j < 0 || yeni_j >= SUTUN) continue; // Alan Dýþý
                                    if (dizi[yeni_i][yeni_j] == 0) continue; // Yayýlacak Yer Yok
                                    if (dizi[yeni_i][yeni_j] == boya_no) continue; // Zaten Yayýldý
                                    dizi[yeni_i][yeni_j] = boya_no;
                                    yayilmaBittiMi = 0;
                                }
                            }
                        }
                    }
                    if (yayilmaBittiMi == 1) break;
                }
            }
        }
    }
    
    // Matrisi Yazdýr
    for (i=0; i<SATIR; i++) {
        printf("\n");
        for (j=0; j<SUTUN; j++)
            printf("%3d ", dizi[i][j]);
    }
    printf("\n%d Adet Farkli Sekil Var", -boya_no);
    
    getch();
}
