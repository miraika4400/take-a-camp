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
 116;
 -23.35000;-4.02500;3.82200;,
 -23.35000;-0.41200;5.18600;,
 -28.23700;-0.41200;3.82200;,
 -26.97000;-3.08800;2.76100;,
 -23.35000;3.20000;3.82200;,
 -26.97000;2.26400;2.76100;,
 -23.35000;4.40500;-0.27100;,
 -28.23700;3.20000;-0.27100;,
 -23.35000;3.20000;-4.36300;,
 -26.97000;2.26400;-3.30200;,
 -23.35000;-0.41200;-5.72700;,
 -28.23700;-0.41200;-4.36300;,
 -23.35000;-4.02500;-4.36300;,
 -26.97000;-3.08800;-3.30200;,
 -23.35000;-5.22900;-0.27100;,
 -28.23700;-4.02500;-0.27100;,
 -23.35000;-4.02500;3.82200;,
 -26.97000;-3.08800;2.76100;,
 -29.86700;-0.41200;-0.27100;,
 -28.23700;-4.02500;-0.27100;,
 -28.23700;-0.41200;-4.36300;,
 -26.97000;-3.08800;-3.30200;,
 -28.23700;3.20000;-0.27100;,
 -26.97000;2.26400;-3.30200;,
 -19.31600;4.32200;8.79900;,
 -10.99200;5.83200;11.74200;,
 -11.58900;12.63500;8.79900;,
 -20.25200;8.46000;6.51000;,
 -0.84900;3.47500;8.79900;,
 -4.15700;11.81100;6.51000;,
 0.05500;-1.97000;9.34600;,
 -0.23900;-3.47300;-0.02900;,
 2.43800;3.76400;-0.02900;,
 -1.72900;13.50100;-0.02900;,
 -0.84900;3.47500;-8.85700;,
 -4.15700;11.81100;-6.56800;,
 0.05500;-1.97000;-7.47200;,
 -10.99200;5.83200;-11.79900;,
 -11.58900;12.63500;-8.85700;,
 -19.31600;4.32200;-8.85700;,
 -19.58200;8.51800;-6.56800;,
 -11.75500;14.51900;-0.02900;,
 -19.81300;9.97500;-0.02900;,
 -11.58900;12.63500;-8.85700;,
 -19.58200;8.51800;-6.56800;,
 -1.72900;13.50100;-0.02900;,
 -4.15700;11.81100;-6.56800;,
 -12.55300;-6.33000;-4.23800;,
 -12.78700;-7.40500;0.37300;,
 -18.89600;-7.08700;0.16500;,
 -18.66200;-6.01200;-4.44600;,
 -12.94500;3.62400;-5.17400;,
 -19.07800;3.44500;-5.36000;,
 -19.29900;6.11000;-0.44000;,
 -13.15400;6.05200;-0.24300;,
 -13.15300;6.05000;-0.25800;,
 -19.29800;6.10900;-0.45500;,
 -19.25600;4.17400;4.68200;,
 -13.12300;4.35200;4.86800;,
 -6.49200;-5.96200;-4.06200;,
 -6.56200;-7.03900;0.55400;,
 -6.86600;4.29200;-4.39800;,
 -6.98700;5.76900;-0.03400;,
 -6.98700;5.76800;-0.04900;,
 -7.02200;4.93200;4.42300;,
 -18.82300;-5.35200;4.65800;,
 -12.71500;-5.67000;4.86600;,
 -6.65300;-5.30200;5.04200;,
 -25.24800;3.74700;-4.90700;,
 -25.32900;4.47100;-0.55700;,
 -25.07400;-5.53400;-0.10200;,
 -25.00300;-4.45700;-4.71800;,
 -25.16400;-3.79700;4.38600;,
 -25.32800;4.47000;-0.57200;,
 -25.40300;4.38000;3.81500;,
 -0.51000;-5.52600;0.67700;,
 -0.61900;-3.31900;4.06400;,
 -0.49500;-3.82300;-2.89000;,
 -0.72400;4.31200;-4.03100;,
 -0.80200;5.02700;0.19600;,
 -0.80200;5.02600;0.18100;,
 -0.87400;4.92700;4.44500;,
 -6.58500;-0.51500;-7.12200;,
 -0.47200;-0.29800;-5.86100;,
 -12.71700;-0.65400;-7.31000;,
 -18.84800;-0.79200;-7.49900;,
 -24.98900;-0.89600;-7.20000;,
 -19.10900;0.27400;7.20200;,
 -25.23200;0.09900;6.52700;,
 -12.97700;0.41200;7.39100;,
 -6.84600;0.55100;7.57900;,
 -0.69500;0.61200;6.69400;,
 -12.71700;-0.65400;-7.31000;,
 -12.94500;3.62400;-5.17400;,
 -6.86600;4.29200;-4.39800;,
 -6.58500;-0.51500;-7.12200;,
 -24.98900;-0.89600;-7.20000;,
 -25.24800;3.74700;-4.90700;,
 -19.07800;3.44500;-5.36000;,
 -18.84800;-0.79200;-7.49900;,
 -6.58500;-0.51500;-7.12200;,
 -6.86600;4.29200;-4.39800;,
 -0.72400;4.31200;-4.03100;,
 -0.47200;-0.29800;-5.86100;,
 -12.97700;0.41200;7.39100;,
 -13.12300;4.35200;4.86800;,
 -19.25600;4.17400;4.68200;,
 -19.10900;0.27400;7.20200;,
 -6.84600;0.55100;7.57900;,
 -7.02200;4.93200;4.42300;,
 -13.12300;4.35200;4.86800;,
 -12.97700;0.41200;7.39100;,
 -19.10900;0.27400;7.20200;,
 -19.25600;4.17400;4.68200;,
 -25.40300;4.38000;3.81500;,
 -25.23200;0.09900;6.52700;;
 
 56;
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
 4;25,28,29,26;,
 4;30,31,32,28;,
 4;28,32,33,29;,
 4;32,34,35,33;,
 4;31,36,34,32;,
 4;34,37,38,35;,
 4;37,39,40,38;,
 4;27,26,41,42;,
 4;42,41,43,44;,
 4;41,45,46,43;,
 4;26,29,45,41;,
 4;47,48,49,50;,
 4;51,52,53,54;,
 4;55,56,57,58;,
 4;48,47,59,60;,
 4;61,51,54,62;,
 4;63,55,58,64;,
 4;65,49,48,66;,
 4;66,48,60,67;,
 4;52,68,69,53;,
 4;70,71,50,49;,
 4;72,70,49,65;,
 4;56,73,74,57;,
 4;67,60,75,76;,
 4;77,75,60,59;,
 4;78,61,62,79;,
 4;80,63,64,81;,
 4;82,83,77,59;,
 4;47,84,82,59;,
 4;85,84,47,50;,
 4;71,86,85,50;,
 4;87,88,72,65;,
 4;89,87,65,66;,
 4;90,89,66,67;,
 4;91,90,67,76;,
 4;85,52,51,84;,
 4;92,93,94,95;,
 4;96,97,98,99;,
 4;100,101,102,103;,
 4;104,105,106,107;,
 4;108,109,110,111;,
 4;112,113,114,115;,
 4;91,81,64,90;;
 
 MeshMaterialList {
  19;
  56;
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5;;
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
  86;
  -0.504123;-0.639554;0.580371;,
  -0.504107;0.639586;0.580350;,
  -0.504081;0.639559;-0.580403;,
  -0.504098;-0.639527;-0.580423;,
  -0.658963;0.000027;-0.752176;,
  -0.302987;-0.703023;-0.643396;,
  -0.625510;-0.780216;-0.000051;,
  -0.302991;-0.703051;0.643363;,
  -0.659004;0.000027;0.752139;,
  -0.302968;0.703068;0.643355;,
  -0.625494;0.780229;-0.000051;,
  -0.302963;0.703040;-0.643388;,
  -0.318156;0.000023;0.948038;,
  -0.283798;0.958884;-0.000044;,
  -0.318156;0.000023;-0.948038;,
  -0.283800;-0.958883;-0.000044;,
  -0.879672;-0.475581;-0.000051;,
  -0.472884;0.672561;0.569247;,
  0.986238;-0.089794;0.138819;,
  0.495384;0.662758;0.561557;,
  0.969292;-0.145337;-0.198369;,
  0.495377;0.662744;-0.561581;,
  -0.479099;0.671155;-0.565699;,
  0.992395;-0.119325;-0.030220;,
  -0.124670;0.762746;-0.634567;,
  -0.391818;0.379340;-0.838200;,
  -0.488623;0.872448;-0.009062;,
  -0.384356;0.357262;0.851255;,
  -0.119005;0.762686;0.635727;,
  0.625239;0.417240;0.659535;,
  0.585059;0.810991;-0.000000;,
  0.806976;0.239245;-0.539955;,
  -0.032430;0.397371;0.917085;,
  0.988640;0.149433;-0.016165;,
  -0.036495;0.409745;-0.911470;,
  -0.187232;0.982304;-0.004809;,
  0.197145;-0.466138;0.862467;,
  0.253310;-0.550940;-0.795172;,
  -0.123819;0.048891;0.991100;,
  -0.061117;-0.054479;-0.996643;,
  -0.029333;0.088443;0.995649;,
  0.034095;-0.014393;-0.999315;,
  0.320490;-0.944582;0.071070;,
  -0.243065;-0.967938;0.063374;,
  0.001643;-0.997545;0.070002;,
  -0.019736;-0.038633;-0.999059;,
  -0.149401;-0.986544;0.066405;,
  -0.082903;0.064458;0.994471;,
  0.089963;-0.124553;0.988126;,
  0.188591;-0.979438;0.071656;,
  0.152460;-0.224549;-0.962462;,
  0.295768;-0.759641;-0.579195;,
  0.182061;-0.783048;-0.594718;,
  0.024470;-0.798019;-0.602135;,
  -0.083127;-0.802709;-0.590549;,
  -0.153353;-0.802275;-0.576921;,
  0.250595;-0.688080;0.680990;,
  -0.188181;-0.725045;0.662494;,
  -0.120728;-0.724471;0.678650;,
  -0.016811;-0.719761;0.694018;,
  0.137725;-0.707769;0.692889;,
  0.016941;0.722402;-0.691266;,
  0.005793;0.907105;-0.420864;,
  -0.060902;0.916794;-0.394689;,
  -0.040892;0.725582;-0.686919;,
  0.059591;0.757481;-0.650131;,
  0.038264;0.948831;-0.313458;,
  -0.126624;0.936571;-0.326804;,
  -0.094124;0.745644;-0.659664;,
  0.070098;0.967528;-0.242848;,
  0.097607;0.772796;-0.627104;,
  -0.017000;0.956256;0.292037;,
  -0.024141;0.800663;0.598628;,
  -0.082517;0.802114;0.591442;,
  -0.082042;0.961557;0.262062;,
  0.020842;0.983904;0.177481;,
  0.021328;0.832081;0.554243;,
  -0.134829;0.818248;0.558830;,
  -0.143618;0.971596;0.188080;,
  0.055814;0.993026;0.103844;,
  0.061035;0.845371;0.530681;,
  -0.879649;0.475624;-0.000051;,
  0.036827;0.471318;-0.881194;,
  0.106929;0.434069;-0.894511;,
  -0.017220;0.561581;0.827243;,
  0.053803;0.525245;0.849249;;
  56;
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
  4;81,10,2,4;,
  4;8,1,10,81;,
  4;27,32,28,17;,
  4;32,29,19,28;,
  4;18,23,33,18;,
  4;29,33,30,19;,
  4;33,31,21,30;,
  4;23,20,31,33;,
  4;31,34,24,21;,
  4;34,25,22,24;,
  4;17,28,35,26;,
  4;26,35,24,22;,
  4;35,30,21,24;,
  4;28,19,30,35;,
  4;53,44,46,54;,
  4;61,64,63,62;,
  4;71,74,73,72;,
  4;44,53,52,49;,
  4;65,61,62,66;,
  4;75,71,72,76;,
  4;58,46,44,59;,
  4;59,44,49,60;,
  4;64,68,67,63;,
  4;43,55,54,46;,
  4;57,43,46,58;,
  4;74,78,77,73;,
  4;60,49,42,56;,
  4;51,42,49,52;,
  4;70,65,66,69;,
  4;79,75,76,80;,
  4;50,37,51,52;,
  4;53,41,50,52;,
  4;45,41,53,54;,
  4;55,39,45,54;,
  4;47,38,57,58;,
  4;40,47,58,59;,
  4;48,40,59,60;,
  4;36,48,60,56;,
  4;45,64,61,41;,
  4;41,61,65,82;,
  4;39,68,64,45;,
  4;50,65,70,83;,
  4;40,72,73,47;,
  4;84,76,72,40;,
  4;47,73,77,38;,
  4;85,80,76,48;;
 }
 MeshTextureCoords {
  116;
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
  0.500000;0.000000;,
  0.500000;0.125000;,
  0.625000;0.125000;,
  0.625000;0.000000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.375000;0.250000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
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
