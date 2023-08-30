// Kullan�c�n�n Girdi�i G�r�nt�de Ka� Adet �ekil Oldu�unu Bulur

// Boya Yayma Y�ntemi:
// 1. 1 ile Kar��la�t���nda Oraya Boya Damlat (Ka��nc� �ekil Oldu�u Numaras�n� Ver (Negatif Olarak))
// 2. 1 ile Kar��la�mad�ysan 5. ad�ma git
// 3. Boyay� Yayabildi�in Kadar Yay (O Say�yla Temas Eden H�creler O Say�ya E�itlensin)
// 4. 1. Ad�ma D�n
// 5. Bitti

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
    int dizi[SATIR][SUTUN], i, j, k, m, yon;
    
    // Matrisi Oku
    for (i=0; i<SATIR; i++)
        for (j=0; j<SUTUN; j++)
            scanf("%d", &dizi[i][j]);
    
    // �ekilleri Say
    int boya_no = 0;
    for (i=0; i<SATIR; i++) {
        for (j=0; j<SUTUN; j++) {
            if (dizi[i][j] == 1) {
                boya_no--;
                dizi[i][j] = boya_no; // Boyay� Damlat
                // Boyay� Yay
                while (1) {
                    int yayilmaBittiMi = 1;
                    for (k=0; k<SATIR; k++) {
                        for (m=0; m<SUTUN; m++) {
                            if (dizi[k][m] == boya_no) {
                                int yonler[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
                                for (yon=0; yon<4; yon++) {
                                    int yeni_i = k + yonler[yon][0];
                                    int yeni_j = m + yonler[yon][1];
                                    if (yeni_i < 0 || yeni_i >= SATIR) continue; // Alan D���
                                    if (yeni_j < 0 || yeni_j >= SUTUN) continue; // Alan D���
                                    if (dizi[yeni_i][yeni_j] == 0) continue; // Yay�lacak Yer Yok
                                    if (dizi[yeni_i][yeni_j] == boya_no) continue; // Zaten Yay�ld�
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
    
    // Matrisi Yazd�r
    for (i=0; i<SATIR; i++) {
        printf("\n");
        for (j=0; j<SUTUN; j++)
            printf("%3d ", dizi[i][j]);
    }
    printf("\n%d Adet Farkli Sekil Var", -boya_no);
    
    getch();
}
