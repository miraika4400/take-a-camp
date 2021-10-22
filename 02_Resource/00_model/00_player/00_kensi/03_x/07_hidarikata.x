xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 93;
 2.31290;-0.40690;-0.43140;,
 2.31290;-0.04560;-0.56780;,
 2.80160;-0.04560;-0.43140;,
 2.67490;-0.31320;-0.32530;,
 2.31290;0.31560;-0.43140;,
 2.67490;0.22200;-0.32530;,
 2.31290;0.43610;-0.02220;,
 2.80160;0.31560;-0.02220;,
 2.31290;0.31560;0.38710;,
 2.67490;0.22200;0.28100;,
 2.31290;-0.04560;0.52350;,
 2.80160;-0.04560;0.38710;,
 2.31290;-0.40690;0.38710;,
 2.67490;-0.31320;0.28100;,
 2.31290;-0.52730;-0.02220;,
 2.80160;-0.40690;-0.02220;,
 2.31290;-0.40690;-0.43140;,
 2.67490;-0.31320;-0.32530;,
 2.96460;-0.04560;-0.02220;,
 2.80160;-0.40690;-0.02220;,
 2.80160;-0.04560;0.38710;,
 2.67490;-0.31320;0.28100;,
 2.80160;0.31560;-0.02220;,
 2.67490;0.22200;0.28100;,
 1.23320;-0.63740;0.37460;,
 1.25660;-0.74490;-0.08650;,
 1.86750;-0.71310;-0.06570;,
 1.84410;-0.60560;0.39540;,
 1.27240;0.35800;0.46810;,
 1.88570;0.34010;0.48680;,
 1.90780;0.60660;-0.00520;,
 1.29330;0.60070;-0.02500;,
 1.29320;0.60060;-0.02350;,
 1.90770;0.60650;-0.00370;,
 1.90350;0.41290;-0.51740;,
 1.29020;0.43080;-0.53610;,
 0.62710;-0.60060;0.35700;,
 0.63410;-0.70830;-0.10460;,
 0.66450;0.42480;0.39060;,
 0.67660;0.57250;-0.04580;,
 0.67650;0.57240;-0.04430;,
 0.68010;0.48880;-0.49150;,
 1.86020;-0.53960;-0.51500;,
 1.24940;-0.57140;-0.53590;,
 0.64320;-0.53460;-0.55340;,
 2.50270;0.37030;0.44150;,
 2.51080;0.44270;0.00650;,
 2.48530;-0.55780;-0.03910;,
 2.47820;-0.45010;0.42260;,
 2.49430;-0.38410;-0.48780;,
 2.51070;0.44260;0.00800;,
 2.51820;0.43360;-0.43080;,
 0.02890;-0.55710;-0.11700;,
 0.03980;-0.33630;-0.45570;,
 0.02740;-0.38680;0.23980;,
 0.05030;0.42680;0.35390;,
 0.05810;0.49830;-0.06880;,
 0.05810;0.49820;-0.06730;,
 0.06530;0.48820;-0.49380;,
 0.63640;-0.05590;0.66300;,
 0.02510;-0.03420;0.53680;,
 1.24960;-0.06980;0.68180;,
 1.86270;-0.08370;0.70060;,
 2.47680;-0.09400;0.67080;,
 1.88880;0.02290;-0.76950;,
 2.50110;0.00550;-0.70200;,
 1.27560;0.03680;-0.78830;,
 0.66250;0.05070;-0.80710;,
 0.04740;0.05680;-0.71860;,
 1.24960;-0.06980;0.68180;,
 1.27240;0.35800;0.46810;,
 0.66450;0.42480;0.39060;,
 0.63640;-0.05590;0.66300;,
 2.47680;-0.09400;0.67080;,
 2.50270;0.37030;0.44150;,
 1.88570;0.34010;0.48680;,
 1.86270;-0.08370;0.70060;,
 0.63640;-0.05590;0.66300;,
 0.66450;0.42480;0.39060;,
 0.05030;0.42680;0.35390;,
 0.02510;-0.03420;0.53680;,
 1.27560;0.03680;-0.78830;,
 1.29020;0.43080;-0.53610;,
 1.90350;0.41290;-0.51740;,
 1.88880;0.02290;-0.76950;,
 0.66250;0.05070;-0.80710;,
 0.68010;0.48880;-0.49150;,
 1.29020;0.43080;-0.53610;,
 1.27560;0.03680;-0.78830;,
 1.88880;0.02290;-0.76950;,
 1.90350;0.41290;-0.51740;,
 2.51820;0.43360;-0.43080;,
 2.50110;0.00550;-0.70200;;
 
 44;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;3,2,18,19;,
 4;19,18,20,21;,
 4;18,22,23,20;,
 4;2,5,22,18;,
 4;24,25,26,27;,
 4;28,29,30,31;,
 4;32,33,34,35;,
 4;25,24,36,37;,
 4;38,28,31,39;,
 4;40,32,35,41;,
 4;42,26,25,43;,
 4;43,25,37,44;,
 4;29,45,46,30;,
 4;47,48,27,26;,
 4;49,47,26,42;,
 4;33,50,51,34;,
 4;44,37,52,53;,
 4;54,52,37,36;,
 4;55,38,39,56;,
 4;57,40,41,58;,
 4;59,60,54,36;,
 4;24,61,59,36;,
 4;62,61,24,27;,
 4;48,63,62,27;,
 4;64,65,49,42;,
 4;66,64,42,43;,
 4;67,66,43,44;,
 4;68,67,44,53;,
 4;62,29,28,61;,
 4;69,70,71,72;,
 4;73,74,75,76;,
 4;77,78,79,80;,
 4;81,82,83,84;,
 4;85,86,87,88;,
 4;89,90,91,92;,
 4;68,58,41,67;;
 
 MeshMaterialList {
  19;
  44;
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.400000;0.400000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.496000;0.496000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.104000;0.104000;0.104000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  67;
  0.504098;-0.639527;-0.580423;,
  0.504081;0.639559;-0.580403;,
  0.504107;0.639586;0.580350;,
  0.504123;-0.639554;0.580371;,
  0.659004;0.000027;0.752139;,
  0.302991;-0.703051;0.643363;,
  0.625510;-0.780216;-0.000051;,
  0.302987;-0.703022;-0.643396;,
  0.658963;0.000027;-0.752176;,
  0.302963;0.703040;-0.643388;,
  0.625494;0.780229;-0.000051;,
  0.302968;0.703068;0.643355;,
  0.318156;0.000023;-0.948038;,
  0.283798;0.958884;-0.000044;,
  0.318156;0.000023;0.948038;,
  0.283800;-0.958883;-0.000044;,
  0.879672;-0.475581;-0.000051;,
  -0.197080;-0.466067;-0.862520;,
  -0.253345;-0.550810;0.795251;,
  0.123770;0.048842;-0.991108;,
  0.061037;-0.054532;0.996645;,
  0.029307;0.088429;-0.995651;,
  -0.034057;-0.014375;0.999317;,
  -0.320356;-0.944622;-0.071143;,
  0.243061;-0.967937;-0.063405;,
  -0.001644;-0.997547;-0.069983;,
  0.019715;-0.038664;0.999058;,
  0.149406;-0.986543;-0.066411;,
  0.082891;0.064424;-0.994474;,
  -0.089949;-0.124511;-0.988133;,
  -0.188529;-0.979448;-0.071682;,
  -0.152493;-0.224523;0.962463;,
  -0.295732;-0.759623;0.579237;,
  -0.182040;-0.783038;0.594738;,
  -0.024462;-0.798015;0.602141;,
  0.083134;-0.802703;0.590557;,
  0.153351;-0.802273;0.576925;,
  -0.250489;-0.688039;-0.681071;,
  0.188185;-0.725104;-0.662428;,
  0.120730;-0.724514;-0.678605;,
  0.016780;-0.719767;-0.694012;,
  -0.137698;-0.707734;-0.692930;,
  -0.016910;0.722438;0.691229;,
  -0.005788;0.907140;0.420790;,
  0.060830;0.916816;0.394650;,
  0.040835;0.725567;0.686939;,
  -0.059550;0.757497;0.650117;,
  -0.038187;0.948846;0.313422;,
  0.126624;0.936571;0.326804;,
  0.094069;0.745602;0.659719;,
  -0.070098;0.967528;0.242848;,
  -0.097649;0.772765;0.627135;,
  0.017049;0.956242;-0.292080;,
  0.024172;0.800636;-0.598664;,
  0.082508;0.802103;-0.591458;,
  0.082064;0.961533;-0.262143;,
  -0.020905;0.983891;-0.177546;,
  -0.021371;0.832044;-0.554298;,
  0.134689;0.818267;-0.558836;,
  0.143527;0.971593;-0.188165;,
  -0.055901;0.993008;-0.103971;,
  -0.061063;0.845323;-0.530754;,
  0.879649;0.475624;-0.000051;,
  -0.036753;0.471399;0.881154;,
  -0.107000;0.433984;0.894544;,
  0.017153;0.561509;-0.827293;,
  -0.053769;0.525207;-0.849274;;
  44;
  4;7,12,8,0;,
  4;12,9,1,8;,
  4;9,13,10,1;,
  4;13,11,2,10;,
  4;11,14,4,2;,
  4;14,5,3,4;,
  4;5,15,6,3;,
  4;15,7,0,6;,
  4;0,8,16,6;,
  4;6,16,4,3;,
  4;62,10,2,4;,
  4;8,1,10,62;,
  4;34,25,27,35;,
  4;42,45,44,43;,
  4;52,55,54,53;,
  4;25,34,33,30;,
  4;46,42,43,47;,
  4;56,52,53,57;,
  4;39,27,25,40;,
  4;40,25,30,41;,
  4;45,49,48,44;,
  4;24,36,35,27;,
  4;38,24,27,39;,
  4;55,59,58,54;,
  4;41,30,23,37;,
  4;32,23,30,33;,
  4;51,46,47,50;,
  4;60,56,57,61;,
  4;31,18,32,33;,
  4;34,22,31,33;,
  4;26,22,34,35;,
  4;36,20,26,35;,
  4;28,19,38,39;,
  4;21,28,39,40;,
  4;29,21,40,41;,
  4;17,29,41,37;,
  4;26,45,42,22;,
  4;22,42,46,63;,
  4;20,49,45,26;,
  4;31,46,51,64;,
  4;21,53,54,28;,
  4;65,57,53,21;,
  4;28,54,58,19;,
  4;66,61,57,29;;
 }
 MeshTextureCoords {
  93;
  0.500000;0.000000;,
  0.500000;0.125000;,
  0.625000;0.125000;,
  0.625000;0.000000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.500000;1.000000;,
  0.625000;1.000000;,
  0.750000;0.125000;,
  0.750000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.000000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  0.562500;0.125000;,
  0.500000;0.125000;,
  0.500000;0.187500;,
  0.562500;0.187500;,
  0.625000;0.125000;,
  0.625000;0.187500;,
  0.875000;0.187500;,
  0.875000;0.125000;,
  0.125000;0.125000;,
  0.125000;0.187500;,
  0.375000;0.187500;,
  0.375000;0.125000;,
  0.562500;0.062500;,
  0.500000;0.062500;,
  0.625000;0.062500;,
  0.875000;0.062500;,
  0.125000;0.062500;,
  0.375000;0.062500;,
  0.437500;0.187500;,
  0.437500;0.125000;,
  0.437500;0.062500;,
  0.625000;0.250000;,
  0.875000;0.250000;,
  0.500000;0.250000;,
  0.562500;0.250000;,
  0.437500;0.250000;,
  0.125000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.000000;,
  0.437500;0.000000;,
  0.562500;0.000000;,
  0.625000;0.000000;,
  0.875000;0.000000;,
  0.125000;0.000000;,
  0.375000;0.000000;,
  0.625000;0.062500;,
  0.625000;0.000000;,
  0.625000;0.125000;,
  0.625000;0.187500;,
  0.625000;0.250000;,
  0.375000;0.187500;,
  0.375000;0.250000;,
  0.375000;0.125000;,
  0.375000;0.062500;,
  0.375000;0.000000;,
  0.125000;0.187500;,
  0.125000;0.187500;,
  0.125000;0.125000;,
  0.125000;0.125000;,
  0.375000;0.062500;,
  0.375000;0.062500;,
  0.375000;0.125000;,
  0.375000;0.125000;,
  0.875000;0.250000;,
  0.875000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.250000;,
  0.625000;0.187500;,
  0.625000;0.187500;,
  0.375000;0.250000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.125000;0.250000;,
  0.625000;0.000000;,
  0.625000;0.000000;,
  0.875000;0.000000;,
  0.875000;0.000000;;
 }
}
