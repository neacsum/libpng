/*------------------------------------------*/
/*  PNGFILE.H -- Header File for pngfile.c*/
/*------------------------------------------*/

/* Copyright 2000, Willem van Schaik.*/

/* This code is released under the libpng license.*/
/* For conditions of distribution and use, see the disclaimer*/
/* and license in png.h*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void PngFileInitialize (HWND hwnd) ;
BOOL PngFileOpenDlg (HWND hwnd, char* pstrFileName, char* pstrTitleName) ;
BOOL PngFileSaveDlg (HWND hwnd, char* pstrFileName, char* pstrTitleName) ;

BOOL PngLoadImage (char* pstrFileName, png_byte** ppbImageData, png_uint_32* piWidth,
                   png_uint_32* piHeight, int* piChannels, png_color* pBkgColor);
BOOL PngSaveImage (char* pstrFileName, png_byte *pDiData,
                   int iWidth, int iHeight, png_color BkgColor);

#ifndef PNG_STDIO_SUPPORTED
static void png_read_data(png_structp png_ptr, png_bytep data, size_t length);
static void png_write_data(png_structp png_ptr, png_bytep data, size_t length);
static void png_flush(png_structp png_ptr);
#endif

