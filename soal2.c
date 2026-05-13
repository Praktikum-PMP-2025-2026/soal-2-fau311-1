/* 
EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
Nama : Syifa Fauziah Prasetyo
NIM : 13224090
Modul : 4 - Foundation of Algorithm
Nama File : PRAK5.c
Deskripsi : 
Jumlah pulau dan ukuran pulau pada suatu grid biner, dimana sel bernilai 1 menunjukkan wilayah aktif dan 0 wilayah kosong 

*/

#include <stdio.h>
#define MAX 100

int R, C;
char grid[MAX][MAX];
int visit[MAX][MAX];

int hitungPulau(int baris, int kolom){
    if(baris < 0 || baris >= R || kolom < 0 || kolom >= C){
        return 0;
    } 
    if(visit[baris][kolom] == 1 || grid[baris][kolom] == '0'){
        return 0;
    }
    
    visit[baris][kolom] = 1; 
    int ukuranPulau = 1; 
    ukuranPulau = ukuranPulau + hitungPulau(baris - 1, kolom); 
    ukuranPulau = ukuranPulau + hitungPulau(baris + 1, kolom); 
    ukuranPulau = ukuranPulau + hitungPulau(baris, kolom - 1); 
    ukuranPulau = ukuranPulau + hitungPulau(baris, kolom + 1);

    return ukuranPulau;
}

int main(){
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++){
        scanf("%s", &grid[i]);
    }

    int jumlahPulau = 0; 
    int ukuranPulau = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(visit[R][C] != 0 && grid[R][C] != '0'){ // telah visit dan grid 1
                jumlahPulau = jumlahPulau + 1;
                int ukuran = hitungPulau(R,C);
                if(ukuran > ukuranPulau){ 
                    ukuranPulau = ukuran;
                }
            }
        }
    }

    printf("ISLANDS %d\n", jumlahPulau);
    printf("LARGEST %d\n", ukuranPulau);
    return 0;
}

/*
Referensi : 
https://www.geeksforgeeks.org/dsa/depth-first-search-or-dfs-for-a-graph/
https://www.geeksforgeeks.org/c/multidimensional-arrays-in-c/

*/
