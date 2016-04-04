/* $Id: algebra_2_4.h 2 2011-03-02 11:01:37Z detchart $ */
/*
 * OpenFEC.org AL-FEC Library.
 * (C) 1997-98 Luigi Rizzo (luigi@iet.unipi.it)
 *
 * Portions derived from code by Phil Karn (karn@ka9q.ampr.org),
 * Robert Morelos-Zaragoza (robert@spectra.eng.hawaii.edu) and Hari
 * Thirumoorthy (harit@spectra.eng.hawaii.edu), Aug 1995
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */

#ifndef OF_GALOIS_FIELD_ALGEBRA_2_4_H
#define OF_GALOIS_FIELD_ALGEBRA_2_4_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "../../../lib_common/of_debug.h"
#include "../../../lib_common/of_openfec_api.h"


#ifdef OF_USE_REED_SOLOMON_2_M_CODEC


#define SWAP(a,b,t) {t tmp; tmp=a; a=b; b=tmp;}

static const gf of_gf_2_4_log[] = {15,0,1,4,2,8,5,10,3,14,9,7,6,13,11,12};

static const gf of_gf_2_4_exp[] = {1,2,4,8,3,6,12,11,5,10,7,14,15,13,9,1};
static const gf of_gf_2_4_inv[] = {0,1,9,14,13,11,7,6,15,2,12,5,10,4,3,8};
static const gf of_gf_2_4_mul_table[][16]={
        {0, 0,  0,  0,  0,  0,  0,  0,        0,        0,        0,        0,        0,        0,        0,        0},
        {0, 1,  2,  3,  4,  5,  6,  7,        8,        9,        10,        11,        12,        13,        14,        15},
        {0, 2,  4,  6,  8,  10, 12, 14,        3,        1,        7,        5,        11,        9,        15,        13},
        {0, 3,  6,  5,  12, 15, 10, 9,        11,        8,        13,        14,        7,        4,        1,        2},
        {0, 4,  8,  12, 3,  7,  11, 15,        6,        2,        14,        10,        5,        1,        13,        9},
        {0, 5,  10, 15, 7,  2,  13, 8,        14,        11,        4,        1,        9,        12,        3,        6},
        {0, 6,  12, 10, 11, 13, 7,  1,        5,        3,        9,        15,        14,        8,        2,        4},
        {0, 7,  14, 9,  15, 8,  1,  6,        13,        10,        3,        4,        2,        5,        12,        11},
        {0, 8,  3,  11, 6,  14, 5,  13,        12,        4,        15,        7,        10,        2,        9,        1},
        {0, 9,  1,  8,  2,  11, 3,  10,        4,        13,        5,        12,        6,        15,        7,        14},
        {0, 10, 7,  13, 14, 4,  9,  3,        15,        5,        8,        2,        1,        11,        6,        12},
        {0, 11, 5,  14, 10, 1,  15, 4,  7,        12,        2,        9,        13,        6,        8,        3},
        {0, 12, 11, 7,  5,  9,  14, 2,  10,        6,        1,        13,        15, 3,        4,        8},
        {0, 13, 9,  4,  1,  12, 8,  5,  2,        15,        11,        6,        3,        14,        10,        7},
        {0, 14, 15, 1,  13, 3,  2,  12, 9,        7,        6,        8,        4,        10,        11,        5},
        {0, 15, 13, 2,  9,  6,  4,  11, 1,  14, 12, 3,        8,        7,        5,        10}};


static const gf of_gf_2_4_opt_mul_table[][256]={
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255},
	{0,2,4,6,8,10,12,14,3,1,7,5,11,9,15,13,32,34,36,38,40,42,44,46,35,33,39,37,43,41,47,45,64,66,68,70,72,74,76,78,67,65,71,69,75,73,79,77,96,98,100,102,104,106,108,110,99,97,103,101,107,105,111,109,128,130,132,134,136,138,140,142,131,129,135,133,139,137,143,141,160,162,164,166,168,170,172,174,163,161,167,165,171,169,175,173,192,194,196,198,200,202,204,206,195,193,199,197,203,201,207,205,224,226,228,230,232,234,236,238,227,225,231,229,235,233,239,237,48,50,52,54,56,58,60,62,51,49,55,53,59,57,63,61,16,18,20,22,24,26,28,30,19,17,23,21,27,25,31,29,112,114,116,118,120,122,124,126,115,113,119,117,123,121,127,125,80,82,84,86,88,90,92,94,83,81,87,85,91,89,95,93,176,178,180,182,184,186,188,190,179,177,183,181,187,185,191,189,144,146,148,150,152,154,156,158,147,145,151,149,155,153,159,157,240,242,244,246,248,250,252,254,243,241,247,245,251,249,255,253,208,210,212,214,216,218,220,222,211,209,215,213,219,217,223,221},
	{0,3,6,5,12,15,10,9,11,8,13,14,7,4,1,2,48,51,54,53,60,63,58,57,59,56,61,62,55,52,49,50,96,99,102,101,108,111,106,105,107,104,109,110,103,100,97,98,80,83,86,85,92,95,90,89,91,88,93,94,87,84,81,82,192,195,198,197,204,207,202,201,203,200,205,206,199,196,193,194,240,243,246,245,252,255,250,249,251,248,253,254,247,244,241,242,160,163,166,165,172,175,170,169,171,168,173,174,167,164,161,162,144,147,150,149,156,159,154,153,155,152,157,158,151,148,145,146,176,179,182,181,188,191,186,185,187,184,189,190,183,180,177,178,128,131,134,133,140,143,138,137,139,136,141,142,135,132,129,130,208,211,214,213,220,223,218,217,219,216,221,222,215,212,209,210,224,227,230,229,236,239,234,233,235,232,237,238,231,228,225,226,112,115,118,117,124,127,122,121,123,120,125,126,119,116,113,114,64,67,70,69,76,79,74,73,75,72,77,78,71,68,65,66,16,19,22,21,28,31,26,25,27,24,29,30,23,20,17,18,32,35,38,37,44,47,42,41,43,40,45,46,39,36,33,34},
	{0,4,8,12,3,7,11,15,6,2,14,10,5,1,13,9,64,68,72,76,67,71,75,79,70,66,78,74,69,65,77,73,128,132,136,140,131,135,139,143,134,130,142,138,133,129,141,137,192,196,200,204,195,199,203,207,198,194,206,202,197,193,205,201,48,52,56,60,51,55,59,63,54,50,62,58,53,49,61,57,112,116,120,124,115,119,123,127,118,114,126,122,117,113,125,121,176,180,184,188,179,183,187,191,182,178,190,186,181,177,189,185,240,244,248,252,243,247,251,255,246,242,254,250,245,241,253,249,96,100,104,108,99,103,107,111,102,98,110,106,101,97,109,105,32,36,40,44,35,39,43,47,38,34,46,42,37,33,45,41,224,228,232,236,227,231,235,239,230,226,238,234,229,225,237,233,160,164,168,172,163,167,171,175,166,162,174,170,165,161,173,169,80,84,88,92,83,87,91,95,86,82,94,90,85,81,93,89,16,20,24,28,19,23,27,31,22,18,30,26,21,17,29,25,208,212,216,220,211,215,219,223,214,210,222,218,213,209,221,217,144,148,152,156,147,151,155,159,150,146,158,154,149,145,157,153},
	{0,5,10,15,7,2,13,8,14,11,4,1,9,12,3,6,80,85,90,95,87,82,93,88,94,91,84,81,89,92,83,86,160,165,170,175,167,162,173,168,174,171,164,161,169,172,163,166,240,245,250,255,247,242,253,248,254,251,244,241,249,252,243,246,112,117,122,127,119,114,125,120,126,123,116,113,121,124,115,118,32,37,42,47,39,34,45,40,46,43,36,33,41,44,35,38,208,213,218,223,215,210,221,216,222,219,212,209,217,220,211,214,128,133,138,143,135,130,141,136,142,139,132,129,137,140,131,134,224,229,234,239,231,226,237,232,238,235,228,225,233,236,227,230,176,181,186,191,183,178,189,184,190,187,180,177,185,188,179,182,64,69,74,79,71,66,77,72,78,75,68,65,73,76,67,70,16,21,26,31,23,18,29,24,30,27,20,17,25,28,19,22,144,149,154,159,151,146,157,152,158,155,148,145,153,156,147,150,192,197,202,207,199,194,205,200,206,203,196,193,201,204,195,198,48,53,58,63,55,50,61,56,62,59,52,49,57,60,51,54,96,101,106,111,103,98,109,104,110,107,100,97,105,108,99,102},
	{0,6,12,10,11,13,7,1,5,3,9,15,14,8,2,4,96,102,108,106,107,109,103,97,101,99,105,111,110,104,98,100,192,198,204,202,203,205,199,193,197,195,201,207,206,200,194,196,160,166,172,170,171,173,167,161,165,163,169,175,174,168,162,164,176,182,188,186,187,189,183,177,181,179,185,191,190,184,178,180,208,214,220,218,219,221,215,209,213,211,217,223,222,216,210,212,112,118,124,122,123,125,119,113,117,115,121,127,126,120,114,116,16,22,28,26,27,29,23,17,21,19,25,31,30,24,18,20,80,86,92,90,91,93,87,81,85,83,89,95,94,88,82,84,48,54,60,58,59,61,55,49,53,51,57,63,62,56,50,52,144,150,156,154,155,157,151,145,149,147,153,159,158,152,146,148,240,246,252,250,251,253,247,241,245,243,249,255,254,248,242,244,224,230,236,234,235,237,231,225,229,227,233,239,238,232,226,228,128,134,140,138,139,141,135,129,133,131,137,143,142,136,130,132,32,38,44,42,43,45,39,33,37,35,41,47,46,40,34,36,64,70,76,74,75,77,71,65,69,67,73,79,78,72,66,68},
	{0,7,14,9,15,8,1,6,13,10,3,4,2,5,12,11,112,119,126,121,127,120,113,118,125,122,115,116,114,117,124,123,224,231,238,233,239,232,225,230,237,234,227,228,226,229,236,235,144,151,158,153,159,152,145,150,157,154,147,148,146,149,156,155,240,247,254,249,255,248,241,246,253,250,243,244,242,245,252,251,128,135,142,137,143,136,129,134,141,138,131,132,130,133,140,139,16,23,30,25,31,24,17,22,29,26,19,20,18,21,28,27,96,103,110,105,111,104,97,102,109,106,99,100,98,101,108,107,208,215,222,217,223,216,209,214,221,218,211,212,210,213,220,219,160,167,174,169,175,168,161,166,173,170,163,164,162,165,172,171,48,55,62,57,63,56,49,54,61,58,51,52,50,53,60,59,64,71,78,73,79,72,65,70,77,74,67,68,66,69,76,75,32,39,46,41,47,40,33,38,45,42,35,36,34,37,44,43,80,87,94,89,95,88,81,86,93,90,83,84,82,85,92,91,192,199,206,201,207,200,193,198,205,202,195,196,194,197,204,203,176,183,190,185,191,184,177,182,189,186,179,180,178,181,188,187},
	{0,8,3,11,6,14,5,13,12,4,15,7,10,2,9,1,128,136,131,139,134,142,133,141,140,132,143,135,138,130,137,129,48,56,51,59,54,62,53,61,60,52,63,55,58,50,57,49,176,184,179,187,182,190,181,189,188,180,191,183,186,178,185,177,96,104,99,107,102,110,101,109,108,100,111,103,106,98,105,97,224,232,227,235,230,238,229,237,236,228,239,231,234,226,233,225,80,88,83,91,86,94,85,93,92,84,95,87,90,82,89,81,208,216,211,219,214,222,213,221,220,212,223,215,218,210,217,209,192,200,195,203,198,206,197,205,204,196,207,199,202,194,201,193,64,72,67,75,70,78,69,77,76,68,79,71,74,66,73,65,240,248,243,251,246,254,245,253,252,244,255,247,250,242,249,241,112,120,115,123,118,126,117,125,124,116,127,119,122,114,121,113,160,168,163,171,166,174,165,173,172,164,175,167,170,162,169,161,32,40,35,43,38,46,37,45,44,36,47,39,42,34,41,33,144,152,147,155,150,158,149,157,156,148,159,151,154,146,153,145,16,24,19,27,22,30,21,29,28,20,31,23,26,18,25,17},
	{0,9,1,8,2,11,3,10,4,13,5,12,6,15,7,14,144,153,145,152,146,155,147,154,148,157,149,156,150,159,151,158,16,25,17,24,18,27,19,26,20,29,21,28,22,31,23,30,128,137,129,136,130,139,131,138,132,141,133,140,134,143,135,142,32,41,33,40,34,43,35,42,36,45,37,44,38,47,39,46,176,185,177,184,178,187,179,186,180,189,181,188,182,191,183,190,48,57,49,56,50,59,51,58,52,61,53,60,54,63,55,62,160,169,161,168,162,171,163,170,164,173,165,172,166,175,167,174,64,73,65,72,66,75,67,74,68,77,69,76,70,79,71,78,208,217,209,216,210,219,211,218,212,221,213,220,214,223,215,222,80,89,81,88,82,91,83,90,84,93,85,92,86,95,87,94,192,201,193,200,194,203,195,202,196,205,197,204,198,207,199,206,96,105,97,104,98,107,99,106,100,109,101,108,102,111,103,110,240,249,241,248,242,251,243,250,244,253,245,252,246,255,247,254,112,121,113,120,114,123,115,122,116,125,117,124,118,127,119,126,224,233,225,232,226,235,227,234,228,237,229,236,230,239,231,238},
	{0,10,7,13,14,4,9,3,15,5,8,2,1,11,6,12,160,170,167,173,174,164,169,163,175,165,168,162,161,171,166,172,112,122,119,125,126,116,121,115,127,117,120,114,113,123,118,124,208,218,215,221,222,212,217,211,223,213,216,210,209,219,214,220,224,234,231,237,238,228,233,227,239,229,232,226,225,235,230,236,64,74,71,77,78,68,73,67,79,69,72,66,65,75,70,76,144,154,151,157,158,148,153,147,159,149,152,146,145,155,150,156,48,58,55,61,62,52,57,51,63,53,56,50,49,59,54,60,240,250,247,253,254,244,249,243,255,245,248,242,241,251,246,252,80,90,87,93,94,84,89,83,95,85,88,82,81,91,86,92,128,138,135,141,142,132,137,131,143,133,136,130,129,139,134,140,32,42,39,45,46,36,41,35,47,37,40,34,33,43,38,44,16,26,23,29,30,20,25,19,31,21,24,18,17,27,22,28,176,186,183,189,190,180,185,179,191,181,184,178,177,187,182,188,96,106,103,109,110,100,105,99,111,101,104,98,97,107,102,108,192,202,199,205,206,196,201,195,207,197,200,194,193,203,198,204},
	{0,11,5,14,10,1,15,4,7,12,2,9,13,6,8,3,176,187,181,190,186,177,191,180,183,188,178,185,189,182,184,179,80,91,85,94,90,81,95,84,87,92,82,89,93,86,88,83,224,235,229,238,234,225,239,228,231,236,226,233,237,230,232,227,160,171,165,174,170,161,175,164,167,172,162,169,173,166,168,163,16,27,21,30,26,17,31,20,23,28,18,25,29,22,24,19,240,251,245,254,250,241,255,244,247,252,242,249,253,246,248,243,64,75,69,78,74,65,79,68,71,76,66,73,77,70,72,67,112,123,117,126,122,113,127,116,119,124,114,121,125,118,120,115,192,203,197,206,202,193,207,196,199,204,194,201,205,198,200,195,32,43,37,46,42,33,47,36,39,44,34,41,45,38,40,35,144,155,149,158,154,145,159,148,151,156,146,153,157,150,152,147,208,219,213,222,218,209,223,212,215,220,210,217,221,214,216,211,96,107,101,110,106,97,111,100,103,108,98,105,109,102,104,99,128,139,133,142,138,129,143,132,135,140,130,137,141,134,136,131,48,59,53,62,58,49,63,52,55,60,50,57,61,54,56,51},
	{0,12,11,7,5,9,14,2,10,6,1,13,15,3,4,8,192,204,203,199,197,201,206,194,202,198,193,205,207,195,196,200,176,188,187,183,181,185,190,178,186,182,177,189,191,179,180,184,112,124,123,119,117,121,126,114,122,118,113,125,127,115,116,120,80,92,91,87,85,89,94,82,90,86,81,93,95,83,84,88,144,156,155,151,149,153,158,146,154,150,145,157,159,147,148,152,224,236,235,231,229,233,238,226,234,230,225,237,239,227,228,232,32,44,43,39,37,41,46,34,42,38,33,45,47,35,36,40,160,172,171,167,165,169,174,162,170,166,161,173,175,163,164,168,96,108,107,103,101,105,110,98,106,102,97,109,111,99,100,104,16,28,27,23,21,25,30,18,26,22,17,29,31,19,20,24,208,220,219,215,213,217,222,210,218,214,209,221,223,211,212,216,240,252,251,247,245,249,254,242,250,246,241,253,255,243,244,248,48,60,59,55,53,57,62,50,58,54,49,61,63,51,52,56,64,76,75,71,69,73,78,66,74,70,65,77,79,67,68,72,128,140,139,135,133,137,142,130,138,134,129,141,143,131,132,136},
	{0,13,9,4,1,12,8,5,2,15,11,6,3,14,10,7,208,221,217,212,209,220,216,213,210,223,219,214,211,222,218,215,144,157,153,148,145,156,152,149,146,159,155,150,147,158,154,151,64,77,73,68,65,76,72,69,66,79,75,70,67,78,74,71,16,29,25,20,17,28,24,21,18,31,27,22,19,30,26,23,192,205,201,196,193,204,200,197,194,207,203,198,195,206,202,199,128,141,137,132,129,140,136,133,130,143,139,134,131,142,138,135,80,93,89,84,81,92,88,85,82,95,91,86,83,94,90,87,32,45,41,36,33,44,40,37,34,47,43,38,35,46,42,39,240,253,249,244,241,252,248,245,242,255,251,246,243,254,250,247,176,189,185,180,177,188,184,181,178,191,187,182,179,190,186,183,96,109,105,100,97,108,104,101,98,111,107,102,99,110,106,103,48,61,57,52,49,60,56,53,50,63,59,54,51,62,58,55,224,237,233,228,225,236,232,229,226,239,235,230,227,238,234,231,160,173,169,164,161,172,168,165,162,175,171,166,163,174,170,167,112,125,121,116,113,124,120,117,114,127,123,118,115,126,122,119},
	{0,14,15,1,13,3,2,12,9,7,6,8,4,10,11,5,224,238,239,225,237,227,226,236,233,231,230,232,228,234,235,229,240,254,255,241,253,243,242,252,249,247,246,248,244,250,251,245,16,30,31,17,29,19,18,28,25,23,22,24,20,26,27,21,208,222,223,209,221,211,210,220,217,215,214,216,212,218,219,213,48,62,63,49,61,51,50,60,57,55,54,56,52,58,59,53,32,46,47,33,45,35,34,44,41,39,38,40,36,42,43,37,192,206,207,193,205,195,194,204,201,199,198,200,196,202,203,197,144,158,159,145,157,147,146,156,153,151,150,152,148,154,155,149,112,126,127,113,125,115,114,124,121,119,118,120,116,122,123,117,96,110,111,97,109,99,98,108,105,103,102,104,100,106,107,101,128,142,143,129,141,131,130,140,137,135,134,136,132,138,139,133,64,78,79,65,77,67,66,76,73,71,70,72,68,74,75,69,160,174,175,161,173,163,162,172,169,167,166,168,164,170,171,165,176,190,191,177,189,179,178,188,185,183,182,184,180,186,187,181,80,94,95,81,93,83,82,92,89,87,86,88,84,90,91,85},
	{0,15,13,2,9,6,4,11,1,14,12,3,8,7,5,10,240,255,253,242,249,246,244,251,241,254,252,243,248,247,245,250,208,223,221,210,217,214,212,219,209,222,220,211,216,215,213,218,32,47,45,34,41,38,36,43,33,46,44,35,40,39,37,42,144,159,157,146,153,150,148,155,145,158,156,147,152,151,149,154,96,111,109,98,105,102,100,107,97,110,108,99,104,103,101,106,64,79,77,66,73,70,68,75,65,78,76,67,72,71,69,74,176,191,189,178,185,182,180,187,177,190,188,179,184,183,181,186,16,31,29,18,25,22,20,27,17,30,28,19,24,23,21,26,224,239,237,226,233,230,228,235,225,238,236,227,232,231,229,234,192,207,205,194,201,198,196,203,193,206,204,195,200,199,197,202,48,63,61,50,57,54,52,59,49,62,60,51,56,55,53,58,128,143,141,130,137,134,132,139,129,142,140,131,136,135,133,138,112,127,125,114,121,118,116,123,113,126,124,115,120,119,117,122,80,95,93,82,89,86,84,91,81,94,92,83,88,87,85,90,160,175,173,162,169,166,164,171,161,174,172,163,168,167,165,170}
};


/*
 * addmul() computes dst[] = dst[] + c * src[]
 */
void	of_galois_field_2_4_addmul1(gf *dst1, gf *src1, gf c, int sz);

/*
 * computes C = AB where A is n*k, B is k*m, C is n*m
 */
void	of_galois_field_2_4_matmul (gf *a, gf *b, gf *c, int n, int k, int m);

int	of_galois_field_2_4_invert_mat (gf *src, int k);

int	of_galois_field_2_4_invert_vdm (gf *src, int k);

#endif //OF_USE_GALOIS_FIELD_CODES_UTILS

#endif //OF_GALOIS_FIELD_ALGEBRA_2_4_H
