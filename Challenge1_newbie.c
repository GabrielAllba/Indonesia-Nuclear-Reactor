#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef char string[50];
#define esc 27
// Tim		: newbie :)
// Anggota :
// 	-	Carolus Seto Arianto
// 	-	Gabriel Allba Shemi Yuma

// g++ Challenge1_newbie.c -o main
// ./main

int main(int argc, char *argv[]) {
	int menu, id_petugas = 2000, status_registrasi =0, status_login=0;
	int jumlah_reaktor, reaktor_aktif,  counter_reaktor_aktif=0, status_inisiasi_reaktor=0;
	int sisa_reaktor_aktif;
	int reaktor_aktif_aktif=0;
	int exit =0;
	int count_reaktor_nonaktif, brp_yg_mau_nonaktif;
	string username, password, nama, login_username, login_password;
	do{
		system("cls");
		printf("\n\t[~ Reaktor Nuclear Indonesia ~]\n\n");
		if(status_login!=0){
			printf("Nama : %s\n", nama);
			printf("ID : %d\n\n", id_petugas);
		}
		printf("[1]. Registrasi Petugas\n");
		printf("[2]. Login\n");
		printf("[3]. Inisialisasi Reaktor\n");
		printf("[4]. Pengaktifan Reaktor\n");
		printf("[5]. Nonaktifkan Reaktor\n");
		printf("[6]. Logout\n");
		printf("[ESC]. EXIT\n");
		menu=getch();
		// printf(">> ");scanf("%d", &menu);
		switch(menu){
			case '1':
				if(status_login==1){
					printf("Anda Sudah Registrasi!\n");
				}
				else{
					printf("\n[~Registrasi Petugas]\n\n");
					printf("\nMasukkan Username\t: ");fflush(stdin);gets(username);
					printf("Masukkan Password\t: ");fflush(stdin);gets(password);
					printf("Masukkan Nama\t\t: ");fflush(stdin);gets(nama);
					if(strcmpi(username, password)==0){
						printf("\nUsername dan Password tidak boleh sama!\n");
						strcpy(username, "");
						strcpy(password, "");
					}
					if(strlen(nama)==0){
						printf("\nNama tidak boleh kosong!\n");
						strcpy(nama, "");
					}
					if(strcmpi(username,password)!=0 && strlen(nama)!=0){
						printf("\nBerhasil Registrasi!\n");
						status_registrasi = 1;
						id_petugas++;
					}
				}
				break;
			case '2':
				if(status_registrasi==0){
					printf("Anda belum Registrasi!\n\n");
				}else if(status_login==1){
					printf("Anda sudah Login!\n\n");
				}
				else{
					int i;
					for(i=1; i<=3; i++){
						printf("\n\n[~ Login Petugas ~]\n\n");
						printf("Username\t: ");fflush(stdin);gets(login_username);
						printf("Password\t: ");fflush(stdin);gets(login_password);
						if(strcmp(login_username, username)==0 && strcmp(login_password, password)==0){
							printf("\n\tNama\t : %s", nama);
							printf("\n\tID\t: %d", id_petugas);
							printf("\n\tLogin Berhasil!\n");
							status_login=1;
							i=4;
						}else{

							printf("Username atau Password Salah!\n");
							printf("Percobaan ke %d\n", i);
							if(i==3){
								printf("Anda Sudah Gagal 3 x!\n");
								return 0;
							}
						}
					}
				}
				break;
			case '3':
				if(status_login==0){
					printf("Belom Login!\n");
				}else if(status_registrasi==0){
					printf("Belom Registrasi!\n");
				}else if(status_inisiasi_reaktor==1){
					printf("Anda hanya dapat mengakses menu ini 1x saja!\n");
				}else{
					printf("\n[~ Inisialisasi Reaktor ~]\n\n");
					printf("\tJumlah Reaktor: ");scanf("%d", &jumlah_reaktor);

					if(jumlah_reaktor<3){
						printf("\n\tReaktor Tidak Boleh < 3!\n");
					}else{
						printf("\n");
					sisa_reaktor_aktif = jumlah_reaktor;
					int x, z,m, pengurang=0;
					for(x=3; x<jumlah_reaktor;x++){
						pengurang++;
					}
					for(z=1; z<=8;z++){

						for(m=1; m<=jumlah_reaktor*6-pengurang;m++){
							if((z==2 ||z==7) && (m>1&&m<jumlah_reaktor*6-pengurang)){
								printf(" ");
							}else if(z==3||z==6){ 
								// print kotak kotak
								if((m+3)%5==0){
									printf(" ");
								}else{
									printf("*");
								}
							}else if(z==4||z==5){
								if(m>=2 && m <=jumlah_reaktor*6-pengurang-1){
									if((m+3)%5==0 || (m+1)%5==0 || (m%5)==0){
										printf(" ");
									}else{
										printf("*");
									}
								}else{
									printf("*");
								}
							}
							else{
								printf("*");
							}
						}
						printf("\n");
					}
					status_inisiasi_reaktor=1;
					}
				}

					
				break;
			case '4': 
				if(status_login==0){
					printf("Belom login!\n");
				}else if(status_registrasi==0){
					printf("Belom Registrasi!\n\n");
				}else if(status_inisiasi_reaktor==0){
					printf("Reaktor belum di Inisiasi!\n");
				}
				else{
					if(counter_reaktor_aktif==jumlah_reaktor){
						printf("\n\t[!] Semua Reaktor Sudah Aktif! [!]\n");
					}else{
						printf("\n\tMasukkan Jumlah Reaktor yang ingin diaktifkan: ");
						scanf("%d", &reaktor_aktif);
						if(reaktor_aktif>jumlah_reaktor){
							printf("\n\t\tReaktor meleibihi! cuma ada %d\n", jumlah_reaktor);
						}
						else if(reaktor_aktif>sisa_reaktor_aktif){
							printf("\n\t\tSisa reaktor non aktif adalah %d", sisa_reaktor_aktif);
						}
						else{
							if(sisa_reaktor_aktif==0){
								printf("\n\tReaktor Dah Aktif Semua!\n");
							}else{
								int r, t,s, pengurang_saat_aktif=0;
								for(r=3; r<jumlah_reaktor;r++){
									pengurang_saat_aktif++;
								}
								for(t=1; t<=8;t++){
									for(s=1; s<=jumlah_reaktor*6-pengurang_saat_aktif;s++){
										if((t==2 ||t==7) && (s>1&&s<jumlah_reaktor*6-pengurang_saat_aktif)){
											printf(" ");
										}
										else if(t==3||t==6){ 
											// print kotak kotak
											if((s+3)%5==0){
												printf(" ");
											}else{
												printf("*");
											}
										}
										else if(t==4||t==5){
											if(s>=2 && s <=jumlah_reaktor*6-pengurang_saat_aktif-1){
												if((s+3)%5==0 || (s+1)%5==0 || (s%5)==0){
													if(((s+1)%5==0 || (s%5==0)) && s<=((reaktor_aktif+reaktor_aktif_aktif)*5)){
														printf("*");
													}else{
														printf(" ");
													}
												}else{
													printf("*");
												}
											}
											else{
												printf("*");
											}
										}
										else{
											printf("*");
										}
									}
										printf("\n");
								}
									reaktor_aktif_aktif +=reaktor_aktif;
									counter_reaktor_aktif+=reaktor_aktif;
									sisa_reaktor_aktif-=reaktor_aktif;
									printf("Sisa reaktor Non aktif: %d\n", sisa_reaktor_aktif);
									printf("Counter Reaktor aktif: %d\n", counter_reaktor_aktif);
							}
						}
					}
				}
				break;
			case '5':
				if(status_login==0){
					printf("\n\tBelom login!\n");
				}else if(status_registrasi==0){
					printf("\n\tBelom Registrasi!\n\n");
				}else if(status_inisiasi_reaktor==0){
					printf("\n\tReaktor belum di Inisiasi!\n");
				}else if(counter_reaktor_aktif<=0){
					printf("\n\tReaktor Belom ada yang aktif!\n");
				}else{
						printf("\n\tMasukkan Jumlah Reaktor yang ingin di NONAKTIFKAN: ");
						scanf("%d", &reaktor_aktif);
						if(reaktor_aktif<1){
							printf("\n\t\tTidak bisa < 1!\n");
						}
						else{
							if(reaktor_aktif>jumlah_reaktor){
								printf("\n\tReaktor meleibihi! cuma ada %d\n", jumlah_reaktor);
							}
							else if(reaktor_aktif>counter_reaktor_aktif){
								printf("\n\tSisa reaktor aktif adalah %d", counter_reaktor_aktif);
							}
							else{
								if(counter_reaktor_aktif==0){
									printf("\n\tReaktor belom ada yang aktif gimana mau nonaktifin!\n");
								}
								else{
									int r, t,s, pengurang_saat_aktif=0;
									for(r=3; r<jumlah_reaktor;r++){
										pengurang_saat_aktif++;
									}
									for(t=1; t<=8;t++){
										for(s=1; s<=jumlah_reaktor*6-pengurang_saat_aktif;s++){
											if((t==2 ||t==7) && (s>1&&s<jumlah_reaktor*6-pengurang_saat_aktif)){
												printf(" ");
											}
											else if(t==3||t==6){ 
												// print kotak kotak
												if((s+3)%5==0){
													printf(" ");
												}else{
													printf("*");
												}
											}
											else if(t==4||t==5){
												if(s>=2 && s <=jumlah_reaktor*6-pengurang_saat_aktif-1){
													if((s+3)%5==0 || (s+1)%5==0 || (s%5)==0){
														if(((s+1)%5==0 || (s%5==0)) && s<=((reaktor_aktif_aktif-reaktor_aktif)*5)){
															printf("*");
														}else{
															printf(" ");
														}
													}else{
														printf("*");
													}
												}
												else{
													printf("*");
												}
											}
											else{
												printf("*");
											}
										}
											printf("\n");
									}
										reaktor_aktif_aktif -=reaktor_aktif;
										counter_reaktor_aktif-=reaktor_aktif;
										sisa_reaktor_aktif+=reaktor_aktif;
										printf("Sisa reaktor non aktif: %d\n", sisa_reaktor_aktif);
										printf("Counter Reaktor aktif: %d\n", counter_reaktor_aktif);
								}
							}
						}
					}
				break;
			case '6':
				if(status_registrasi==0){
					printf("Anda belum Registrasi!\n\n");
				}else if(status_login==0){
					printf("Anda belum Login!\n\n");
				}else{
					status_login=0;
					status_registrasi=0;
					status_inisiasi_reaktor=0;
					reaktor_aktif_aktif=0;
					sisa_reaktor_aktif=0;
					counter_reaktor_aktif=0;
					printf("Logout berhasil!\n");
				}
				break;
			case esc:
				exit = 1;
				break;
		}getch();

	}while(exit==0); 
	
	return 0;
}
