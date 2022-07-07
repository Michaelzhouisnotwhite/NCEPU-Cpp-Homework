#include <Windows.h>
#include <stdio.h>



BOOL CALLBACK EnumFontFamEx(LPLOGFONT lplf,LPTEXTMETRIC lptm,int iType,LPARAM lpData)

{

		int* iArrayCount;

			iArrayCount = (int*)lpData;



				if(iType & DEVICE_FONTTYPE)

						{

									iArrayCount[0]++;

										}

					else if(iType & RASTER_FONTTYPE)

							{

										iArrayCount[1]++;

											}

						else if(iType & TRUETYPE_FONTTYPE)

								{

											iArrayCount[2]++;

												}

							else

									{

												iArrayCount[3]++;

													}



								printf("Font:%s\n",lplf->lfFaceName);



									return (iArrayCount[0]+iArrayCount[1]+iArrayCount[2]+iArrayCount[3])?true:false;

}



int main()

{

		HDC hdc;

			hdc = GetDC(NULL);

				LOGFONT lf;



					int iArrayCount[] = {0,0,0,0};



						memset(&lf,0,sizeof(LOGFONT));

							lf.lfCharSet = DEFAULT_CHARSET;

								lf.lfFaceName[0] = NULL;





									EnumFontFamiliesEx(hdc,&lf,(FONTENUMPROC)EnumFontFamEx,(LPARAM)iArrayCount,0);



										printf("DEVICE_FONTTYPE:%d\n",iArrayCount[0]);

											printf("RASTER_FONTTYPE:%d\n",iArrayCount[1]);

												printf("TRUETYPE_FONTTYPE:%d\n",iArrayCount[2]);



													ReleaseDC(NULL,hdc);

														return 0;

}
