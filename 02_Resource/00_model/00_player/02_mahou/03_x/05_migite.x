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
 267;
 -0.83426;-0.29004;-0.16100;,
 -0.93526;-0.00154;-0.21420;,
 -0.54576;-0.00154;-0.28270;,
 -0.54576;-0.39104;-0.21420;,
 -0.15636;-0.00154;-0.21420;,
 -0.25726;-0.29004;-0.16100;,
 -0.54576;0.38786;-0.21420;,
 -0.25726;0.28696;-0.16100;,
 -0.83426;0.28696;-0.16100;,
 -0.93526;0.38786;-0.00880;,
 -0.54576;0.51776;-0.00880;,
 -0.15636;0.38786;-0.00880;,
 -0.54576;0.38786;0.19660;,
 -0.25726;0.28696;0.14340;,
 -0.83426;0.28696;0.14340;,
 -0.93526;-0.00154;0.19660;,
 -0.54576;-0.00154;0.26510;,
 -0.15636;-0.00154;0.19660;,
 -0.54576;-0.39104;0.19660;,
 -0.25726;-0.29004;0.14340;,
 -0.83426;-0.29004;0.14340;,
 -0.93526;-0.39104;-0.00880;,
 -0.54576;-0.52084;-0.00880;,
 -0.15636;-0.39104;-0.00880;,
 -0.54576;-0.39104;-0.21420;,
 -0.25726;-0.29004;-0.16100;,
 -0.83426;-0.29004;-0.16100;,
 -0.02646;-0.00154;-0.00880;,
 -0.15636;-0.39104;-0.00880;,
 -0.15636;-0.00154;0.19660;,
 -0.25726;-0.29004;0.14340;,
 -0.15636;0.38786;-0.00880;,
 -0.25726;0.28696;0.14340;,
 -0.83426;-0.29004;0.14340;,
 -0.93526;-0.00154;0.19660;,
 -1.06506;-0.00154;-0.00880;,
 -0.93526;-0.39104;-0.00880;,
 -0.93526;0.38786;-0.00880;,
 -0.83426;0.28696;0.14340;,
 -0.10076;-0.29004;-0.16100;,
 -0.13866;-0.00154;-0.21420;,
 0.00734;-0.00154;-0.28270;,
 0.00734;-0.39104;-0.21420;,
 0.15334;-0.00154;-0.21420;,
 0.11544;-0.29004;-0.16100;,
 0.00734;0.38786;-0.21420;,
 0.11544;0.28696;-0.16100;,
 -0.10076;0.28696;-0.16100;,
 -0.13866;0.38786;-0.00880;,
 0.00734;0.51776;-0.00880;,
 0.15334;0.38786;-0.00880;,
 0.00734;0.38786;0.19660;,
 0.11544;0.28696;0.14340;,
 -0.10076;0.28696;0.14340;,
 -0.13866;-0.00154;0.19660;,
 0.00734;-0.00154;0.26510;,
 0.15334;-0.00154;0.19660;,
 0.00734;-0.39104;0.19660;,
 0.11544;-0.29004;0.14340;,
 -0.10076;-0.29004;0.14340;,
 -0.13866;-0.39104;-0.00880;,
 0.00734;-0.52084;-0.00880;,
 0.15334;-0.39104;-0.00880;,
 0.00734;-0.39104;-0.21420;,
 0.11544;-0.29004;-0.16100;,
 -0.10076;-0.29004;-0.16100;,
 0.20194;-0.00154;-0.00880;,
 0.15334;-0.39104;-0.00880;,
 0.15334;-0.00154;0.19660;,
 0.11544;-0.29004;0.14340;,
 0.15334;0.38786;-0.00880;,
 0.11544;0.28696;0.14340;,
 -0.10076;-0.29004;0.14340;,
 -0.13866;-0.00154;0.19660;,
 -0.18726;-0.00154;-0.00880;,
 -0.13866;-0.39104;-0.00880;,
 -0.13866;0.38786;-0.00880;,
 -0.10076;0.28696;0.14340;,
 -0.82756;6.29886;-0.23490;,
 -0.80966;6.29886;-0.32490;,
 -0.80966;6.29886;-0.14490;,
 -0.75866;6.29886;-0.06850;,
 -0.75866;6.29886;-0.40120;,
 -0.68236;6.29886;-0.01760;,
 -0.68236;6.29886;-0.45220;,
 -0.59236;6.29886;0.00030;,
 -0.59236;6.29886;-0.47010;,
 -0.50236;6.29886;-0.01760;,
 -0.50236;6.29886;-0.45220;,
 -0.42606;6.29886;-0.06850;,
 -0.42606;6.29886;-0.40120;,
 -0.37506;6.29886;-0.14490;,
 -0.37506;6.29886;-0.32490;,
 -0.35716;6.29886;-0.23490;,
 -0.85526;6.42666;-0.34380;,
 -0.59236;6.95866;-0.23490;,
 -0.79366;6.42666;-0.43610;,
 -0.70126;6.42666;-0.49780;,
 -0.59236;6.42666;-0.51940;,
 -0.48346;6.42666;-0.49780;,
 -0.39116;6.42666;-0.43610;,
 -0.32946;6.42666;-0.34380;,
 -0.30786;6.42666;-0.23490;,
 -0.32946;6.42666;-0.12600;,
 -0.39116;6.42666;-0.03360;,
 -0.48346;6.42666;0.02810;,
 -0.59236;6.42666;0.04970;,
 -0.70126;6.42666;0.02810;,
 -0.79366;6.42666;-0.03360;,
 -0.85526;6.42666;-0.12600;,
 -0.87696;6.42666;-0.23490;,
 -0.85526;6.42666;-0.34380;,
 -0.85526;6.42666;-0.34380;,
 -0.85526;6.36766;-0.34380;,
 -0.87696;6.36766;-0.23490;,
 -0.87696;6.42666;-0.23490;,
 -0.85526;6.36766;-0.12600;,
 -0.85526;6.42666;-0.12600;,
 -0.79366;6.36766;-0.03360;,
 -0.79366;6.42666;-0.03360;,
 -0.70126;6.36766;0.02810;,
 -0.70126;6.42666;0.02810;,
 -0.59236;6.36766;0.04970;,
 -0.59236;6.42666;0.04970;,
 -0.48346;6.36766;0.02810;,
 -0.48346;6.42666;0.02810;,
 -0.39116;6.36766;-0.03360;,
 -0.39116;6.42666;-0.03360;,
 -0.32946;6.36766;-0.12600;,
 -0.32946;6.42666;-0.12600;,
 -0.30786;6.36766;-0.23490;,
 -0.30786;6.42666;-0.23490;,
 -0.32946;6.36766;-0.34380;,
 -0.32946;6.42666;-0.34380;,
 -0.39116;6.36766;-0.43610;,
 -0.39116;6.42666;-0.43610;,
 -0.48346;6.36766;-0.49780;,
 -0.48346;6.42666;-0.49780;,
 -0.59236;6.36766;-0.51940;,
 -0.59236;6.42666;-0.51940;,
 -0.70126;6.36766;-0.49780;,
 -0.70126;6.42666;-0.49780;,
 -0.79366;6.36766;-0.43610;,
 -0.79366;6.42666;-0.43610;,
 -0.45886;-9.50683;-0.18160;,
 -0.39296;6.05046;-0.15120;,
 -0.42596;6.05046;-0.09980;,
 -0.48086;-9.50683;-0.14720;,
 -0.48816;-9.53574;-0.17610;,
 -0.46856;-9.53574;-0.24280;,
 -0.44686;-9.50683;-0.22240;,
 -0.45886;-9.50683;-0.18160;,
 -0.51306;-9.50683;-0.11930;,
 -0.54066;-9.53574;-0.13060;,
 -0.48816;-9.53574;-0.17610;,
 -0.47406;6.05046;-0.05810;,
 -0.52956;6.05046;-0.03280;,
 -0.55026;-9.50683;-0.10240;,
 -0.59236;-9.50683;-0.09630;,
 -0.60946;-9.53574;-0.12070;,
 -0.54066;-9.53574;-0.13060;,
 -0.59256;6.05046;-0.02370;,
 -0.65306;6.05046;-0.03240;,
 -0.63276;-9.50683;-0.10210;,
 -0.67146;-9.50683;-0.11980;,
 -0.67266;-9.53574;-0.14960;,
 -0.60946;-9.53574;-0.12070;,
 -0.71096;6.05046;-0.05880;,
 -0.75706;6.05046;-0.09880;,
 -0.70236;-9.50683;-0.14650;,
 -0.72536;-9.50683;-0.18240;,
 -0.71026;-9.53574;-0.20810;,
 -0.67266;-9.53574;-0.14960;,
 -0.79146;6.05046;-0.15240;,
 -0.80876;6.05046;-0.21100;,
 -0.73686;-9.50683;-0.22150;,
 -0.73686;-9.50683;-0.26410;,
 -0.71026;-9.53574;-0.27760;,
 -0.71026;-9.53574;-0.20810;,
 -0.80876;6.05046;-0.27460;,
 -0.79146;6.05046;-0.33320;,
 -0.72536;-9.50683;-0.30330;,
 -0.70236;-9.50683;-0.33910;,
 -0.67266;-9.53574;-0.33600;,
 -0.71026;-9.53574;-0.27760;,
 -0.75706;6.05046;-0.38680;,
 -0.71096;6.05046;-0.42680;,
 -0.67146;-9.50683;-0.36580;,
 -0.63276;-9.50683;-0.38350;,
 -0.60946;-9.53574;-0.36490;,
 -0.67266;-9.53574;-0.33600;,
 -0.65306;6.05046;-0.45320;,
 -0.59256;6.05046;-0.46190;,
 -0.59236;-9.50683;-0.38930;,
 -0.55026;-9.50683;-0.38320;,
 -0.54066;-9.53574;-0.35500;,
 -0.60946;-9.53574;-0.36490;,
 -0.52956;6.05046;-0.45280;,
 -0.47406;6.05046;-0.42750;,
 -0.51306;-9.50683;-0.36630;,
 -0.48086;-9.50683;-0.33840;,
 -0.48816;-9.53574;-0.30950;,
 -0.54066;-9.53574;-0.35500;,
 -0.42596;6.05046;-0.38580;,
 -0.39296;6.05046;-0.33440;,
 -0.45886;-9.50683;-0.30410;,
 -0.44686;-9.50683;-0.26320;,
 -0.46856;-9.53574;-0.24280;,
 -0.48816;-9.53574;-0.30950;,
 -0.37496;6.05046;-0.27330;,
 -0.37496;6.05046;-0.21230;,
 -0.34776;6.12166;-0.08720;,
 -0.47026;6.12166;0.01890;,
 -0.39296;6.05046;-0.15120;,
 -0.30206;6.12166;-0.24280;,
 -0.34776;6.12166;-0.08720;,
 -0.47026;6.12166;0.01890;,
 -0.63496;6.12166;0.04200;,
 -0.63496;6.12166;0.04200;,
 -0.78246;6.12166;-0.02530;,
 -0.78246;6.12166;-0.02530;,
 -0.87016;6.12166;-0.16170;,
 -0.87016;6.12166;-0.16170;,
 -0.87016;6.12166;-0.32390;,
 -0.87016;6.12166;-0.32390;,
 -0.78246;6.12166;-0.46030;,
 -0.78246;6.12166;-0.46030;,
 -0.63496;6.12166;-0.52760;,
 -0.63496;6.12166;-0.52760;,
 -0.47026;6.12166;-0.50460;,
 -0.47026;6.12166;-0.50460;,
 -0.34776;6.12166;-0.39840;,
 -0.34776;6.12166;-0.39840;,
 -0.30206;6.12166;-0.24280;,
 -0.71026;-9.53574;-0.27760;,
 -0.67266;-9.53574;-0.33600;,
 -0.71026;-9.53574;-0.20810;,
 -0.67266;-9.53574;-0.14960;,
 -0.60946;-9.53574;-0.12070;,
 -0.60946;-9.53574;-0.36490;,
 -0.54066;-9.53574;-0.13060;,
 -0.54066;-9.53574;-0.35500;,
 -0.48816;-9.53574;-0.17610;,
 -0.48816;-9.53574;-0.30950;,
 -0.46856;-9.53574;-0.24280;,
 -0.87016;6.28156;-0.16170;,
 -0.78246;6.28156;-0.02530;,
 -0.87016;6.28156;-0.32390;,
 -0.78246;6.28156;-0.46030;,
 -0.63496;6.28156;-0.52760;,
 -0.63496;6.28156;0.04200;,
 -0.47026;6.28156;-0.50460;,
 -0.47026;6.28156;0.01890;,
 -0.34776;6.28156;-0.39840;,
 -0.34776;6.28156;-0.08720;,
 -0.30206;6.28156;-0.24280;,
 -0.34776;6.12166;-0.08720;,
 -0.47026;6.12166;0.01890;,
 -0.63496;6.12166;0.04200;,
 -0.78246;6.12166;-0.02530;,
 -0.87016;6.12166;-0.16170;,
 -0.87016;6.12166;-0.32390;,
 -0.78246;6.12166;-0.46030;,
 -0.63496;6.12166;-0.52760;,
 -0.47026;6.12166;-0.50460;,
 -0.34776;6.12166;-0.39840;,
 -0.30206;6.12166;-0.24280;;
 
 205;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;2,6,7,4;,
 4;1,8,6,2;,
 4;8,9,10,6;,
 4;6,10,11,7;,
 4;10,12,13,11;,
 4;9,14,12,10;,
 4;14,15,16,12;,
 4;12,16,17,13;,
 4;16,18,19,17;,
 4;15,20,18,16;,
 4;20,21,22,18;,
 4;18,22,23,19;,
 4;22,24,25,23;,
 4;21,26,24,22;,
 4;5,4,27,28;,
 4;28,27,29,30;,
 4;27,31,32,29;,
 4;4,7,31,27;,
 4;33,34,35,36;,
 4;36,35,1,0;,
 4;35,37,8,1;,
 4;34,38,37,35;,
 4;39,40,41,42;,
 4;42,41,43,44;,
 4;41,45,46,43;,
 4;40,47,45,41;,
 4;47,48,49,45;,
 4;45,49,50,46;,
 4;49,51,52,50;,
 4;48,53,51,49;,
 4;53,54,55,51;,
 4;51,55,56,52;,
 4;55,57,58,56;,
 4;54,59,57,55;,
 4;59,60,61,57;,
 4;57,61,62,58;,
 4;61,63,64,62;,
 4;60,65,63,61;,
 4;44,43,66,67;,
 4;67,66,68,69;,
 4;66,70,71,68;,
 4;43,46,70,66;,
 4;72,73,74,75;,
 4;75,74,40,39;,
 4;74,76,47,40;,
 4;73,77,76,74;,
 3;78,79,80;,
 3;80,79,81;,
 3;79,82,81;,
 3;81,82,83;,
 3;82,84,83;,
 3;83,84,85;,
 3;84,86,85;,
 3;85,86,87;,
 3;86,88,87;,
 3;87,88,89;,
 3;88,90,89;,
 3;89,90,91;,
 3;90,92,91;,
 3;91,92,93;,
 3;94,95,96;,
 3;96,95,97;,
 3;97,95,98;,
 3;98,95,99;,
 3;99,95,100;,
 3;100,95,101;,
 3;101,95,102;,
 3;102,95,103;,
 3;103,95,104;,
 3;104,95,105;,
 3;105,95,106;,
 3;106,95,107;,
 3;107,95,108;,
 3;108,95,109;,
 3;109,95,110;,
 3;110,95,111;,
 4;112,113,114,115;,
 4;115,114,116,117;,
 4;117,116,118,119;,
 4;119,118,120,121;,
 4;121,120,122,123;,
 4;123,122,124,125;,
 4;125,124,126,127;,
 4;127,126,128,129;,
 4;129,128,130,131;,
 4;131,130,132,133;,
 4;133,132,134,135;,
 4;135,134,136,137;,
 4;137,136,138,139;,
 4;139,138,140,141;,
 4;141,140,142,143;,
 4;143,142,113,112;,
 4;113,79,78,114;,
 4;114,78,80,116;,
 4;116,80,81,118;,
 4;118,81,83,120;,
 4;120,83,85,122;,
 4;122,85,87,124;,
 4;124,87,89,126;,
 4;126,89,91,128;,
 4;128,91,93,130;,
 4;130,93,92,132;,
 4;132,92,90,134;,
 4;134,90,88,136;,
 4;136,88,86,138;,
 4;138,86,84,140;,
 4;140,84,82,142;,
 4;142,82,79,113;,
 4;144,145,146,147;,
 4;148,149,150,151;,
 4;147,152,153,154;,
 4;152,155,156,157;,
 4;157,158,159,160;,
 4;158,161,162,163;,
 4;163,164,165,166;,
 4;164,167,168,169;,
 4;169,170,171,172;,
 4;170,173,174,175;,
 4;175,176,177,178;,
 4;176,179,180,181;,
 4;181,182,183,184;,
 4;182,185,186,187;,
 4;187,188,189,190;,
 4;188,191,192,193;,
 4;193,194,195,196;,
 4;194,197,198,199;,
 4;199,200,201,202;,
 4;200,203,204,205;,
 4;205,206,207,208;,
 4;206,209,210,150;,
 4;211,212,155,146;,
 4;213,210,214,215;,
 4;216,217,161,156;,
 4;218,219,167,162;,
 4;220,221,173,168;,
 4;222,223,179,174;,
 4;224,225,185,180;,
 4;226,227,191,186;,
 4;228,229,197,192;,
 4;230,231,203,198;,
 4;232,233,209,204;,
 4;147,146,155,152;,
 4;157,156,161,158;,
 4;163,162,167,164;,
 4;169,168,173,170;,
 4;175,174,179,176;,
 4;181,180,185,182;,
 4;187,186,191,188;,
 4;193,192,197,194;,
 4;199,198,203,200;,
 4;205,204,209,206;,
 4;150,210,213,151;,
 3;234,235,236;,
 3;236,235,237;,
 3;237,235,238;,
 3;235,239,238;,
 3;238,239,240;,
 3;239,241,240;,
 3;240,241,242;,
 3;241,243,242;,
 3;242,243,244;,
 3;245,246,247;,
 3;247,246,248;,
 3;248,246,249;,
 3;246,250,249;,
 3;249,250,251;,
 3;250,252,251;,
 3;251,252,253;,
 3;252,254,253;,
 3;253,254,255;,
 3;144,147,154;,
 3;152,157,153;,
 3;158,163,159;,
 3;164,169,165;,
 3;170,175,171;,
 3;176,181,177;,
 3;182,187,183;,
 3;188,193,189;,
 3;194,199,195;,
 3;200,205,201;,
 3;206,150,207;,
 3;146,145,211;,
 3;156,155,212;,
 3;162,161,217;,
 3;168,167,219;,
 3;174,173,221;,
 3;180,179,223;,
 3;186,185,225;,
 3;192,191,227;,
 3;198,197,229;,
 3;204,203,231;,
 3;210,209,233;,
 4;256,254,252,257;,
 4;257,252,250,258;,
 4;258,250,246,259;,
 4;259,246,245,260;,
 4;260,245,247,261;,
 4;261,247,248,262;,
 4;262,248,249,263;,
 4;263,249,251,264;,
 4;264,251,253,265;,
 4;265,253,255,266;,
 4;266,255,254,256;;
 
 MeshMaterialList {
  13;
  205;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
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
   0.400000;0.400000;0.400000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.032000;0.032000;0.032000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.024000;0.024000;0.024000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.032000;0.032000;0.032000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.248000;0.600000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.024000;0.008000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.080000;0.016000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.032000;0.032000;0.032000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.032000;0.032000;0.032000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.080000;0.016000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.032000;0.032000;0.032000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.032000;0.032000;0.032000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.080000;0.016000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  196;
  -0.458805;-0.458805;-0.760918;,
  0.458823;-0.458797;-0.760912;,
  -0.458797;0.458823;-0.760912;,
  0.458816;0.458816;-0.760905;,
  -0.458797;0.458823;0.760912;,
  0.458816;0.458816;0.760905;,
  -0.458805;-0.458805;0.760918;,
  0.458823;-0.458797;0.760912;,
  -0.563077;0.563092;-0.604874;,
  0.532209;0.000016;0.846613;,
  0.000016;-0.532209;0.846613;,
  -0.532209;0.000016;0.846613;,
  0.563092;-0.563077;0.604874;,
  -0.563078;-0.563078;0.604885;,
  0.000016;-0.532209;-0.846613;,
  0.532209;0.000016;-0.846613;,
  0.000016;0.532209;-0.846613;,
  -0.532209;0.000016;-0.846613;,
  0.563091;0.563091;-0.604862;,
  0.000016;0.532209;0.846613;,
  0.000011;0.000011;-1.000000;,
  0.000019;0.798713;-0.601712;,
  0.000011;0.000011;1.000000;,
  0.000019;-0.798728;0.601693;,
  0.798713;0.000019;-0.601712;,
  -0.798728;0.000019;0.601693;,
  -0.750901;-0.327883;-0.573272;,
  0.750901;-0.327883;-0.573272;,
  -0.750892;0.327905;-0.573271;,
  0.750892;0.327905;-0.573271;,
  -0.750892;0.327905;0.573271;,
  0.750892;0.327905;0.573271;,
  -0.750901;-0.327883;0.573272;,
  0.750901;-0.327883;0.573272;,
  -0.910598;0.413293;0.000000;,
  0.785571;0.000010;0.618771;,
  -0.266559;-0.385156;0.883516;,
  -0.785571;0.000010;0.618771;,
  0.910605;-0.413277;-0.000000;,
  -0.910605;-0.413277;0.000000;,
  0.266559;-0.385156;-0.883516;,
  0.785571;0.000010;-0.618771;,
  -0.266550;0.385173;-0.883511;,
  -0.785571;0.000010;-0.618771;,
  0.910598;0.413293;0.000000;,
  0.596242;0.403164;0.694229;,
  0.000000;0.000013;-1.000000;,
  -0.746005;0.665941;0.000000;,
  0.000000;0.000013;1.000000;,
  -0.746019;-0.665924;0.000000;,
  1.000000;0.000008;0.000000;,
  -1.000000;0.000008;0.000000;,
  -0.896078;0.243638;-0.371059;,
  -0.685877;0.243677;-0.685707;,
  -0.370773;0.243641;-0.896196;,
  -0.000000;0.243593;-0.969878;,
  0.370998;0.243642;-0.896102;,
  0.685802;0.243623;-0.685802;,
  0.896102;0.243642;-0.370998;,
  0.969878;0.243593;0.000000;,
  0.896196;0.243641;0.370773;,
  0.685965;0.243675;0.685619;,
  0.370992;0.243708;0.896087;,
  -0.000000;0.243664;0.969860;,
  -0.370767;0.243707;0.896180;,
  -0.686041;0.243729;0.685525;,
  -0.896172;0.243637;0.370834;,
  -0.969858;0.243669;0.000000;,
  0.000007;0.553545;-0.832819;,
  -0.951624;-0.307265;0.000000;,
  -0.879207;-0.307281;-0.364107;,
  -0.879303;-0.307281;0.363875;,
  -0.673031;-0.307466;0.672677;,
  -0.363781;-0.307480;0.879272;,
  -0.000000;-0.307453;0.951563;,
  0.363967;-0.307420;0.879216;,
  0.673016;-0.307262;0.672785;,
  0.879375;-0.307104;0.363851;,
  0.951704;-0.307016;0.000000;,
  0.879275;-0.307120;-0.364079;,
  0.672925;-0.307156;-0.672925;,
  0.364079;-0.307109;-0.879278;,
  -0.000000;-0.306992;-0.951712;,
  -0.363896;-0.307158;-0.879337;,
  -0.672946;-0.307333;-0.672822;,
  -0.597747;-0.801685;0.000000;,
  -0.332975;-0.932796;-0.137911;,
  -0.419132;-0.891202;0.173457;,
  -0.254775;-0.932851;0.254711;,
  -0.137736;-0.932847;0.332904;,
  -0.000000;-0.932842;0.360285;,
  0.137801;-0.932831;0.332923;,
  0.254865;-0.932795;0.254827;,
  0.333140;-0.932745;0.137857;,
  0.598026;-0.801477;0.000000;,
  0.419222;-0.891129;-0.173614;,
  0.254911;-0.932760;-0.254911;,
  0.137943;-0.932749;-0.333093;,
  -0.000000;-0.932716;-0.360613;,
  -0.137883;-0.932762;-0.333081;,
  -0.254836;-0.932809;-0.254808;,
  0.853000;-0.345063;0.391565;,
  0.343048;-0.913171;0.220082;,
  0.711401;-0.345370;0.612069;,
  0.504711;-0.345284;0.791231;,
  0.169123;-0.913134;0.370923;,
  0.266354;-0.344938;0.900041;,
  -0.001989;-0.345100;0.938564;,
  -0.057936;-0.913166;0.403449;,
  -0.262101;-0.345289;0.901154;,
  -0.509130;-0.345480;0.788308;,
  -0.319300;-0.873021;0.368621;,
  -0.707573;-0.345692;0.616310;,
  -0.854653;-0.345483;0.387570;,
  -0.468081;-0.872941;0.137382;,
  -0.928518;-0.345365;0.136300;,
  -0.928583;-0.345279;-0.136075;,
  -0.574739;-0.800748;-0.168750;,
  -0.854638;-0.345364;-0.387707;,
  -0.707362;-0.345602;-0.616602;,
  -0.227733;-0.937514;-0.263070;,
  -0.509131;-0.345475;-0.788310;,
  -0.262101;-0.345285;-0.901156;,
  -0.057940;-0.913182;-0.403413;,
  -0.001995;-0.345158;-0.938543;,
  0.266354;-0.344995;-0.900019;,
  0.169118;-0.913149;-0.370889;,
  0.504713;-0.345277;-0.791232;,
  0.711062;-0.345485;-0.612398;,
  0.410547;-0.872901;-0.263617;,
  0.852796;-0.345300;-0.391800;,
  0.929352;-0.345074;-0.131257;,
  0.599394;-0.800454;0.000078;,
  0.929351;-0.345015;0.131419;,
  0.700337;-0.371834;0.609317;,
  0.753939;-0.443276;0.484853;,
  0.844968;-0.373005;0.383270;,
  0.259160;-0.367272;0.893279;,
  0.371830;-0.438794;0.818048;,
  0.503643;-0.370291;0.780531;,
  -0.263888;-0.368251;0.891490;,
  -0.128500;-0.436949;0.890260;,
  0.002320;-0.366366;0.930468;,
  -0.703162;-0.371969;0.605972;,
  -0.587271;-0.441559;0.678335;,
  -0.500212;-0.370021;0.782862;,
  -0.918422;-0.373523;0.130314;,
  -0.859487;-0.444327;0.252697;,
  -0.842937;-0.372997;0.387725;,
  -0.842925;-0.372931;-0.387814;,
  -0.859513;-0.444265;-0.252719;,
  -0.918437;-0.373518;-0.130222;,
  -0.500209;-0.370045;-0.782852;,
  -0.587298;-0.441516;-0.678340;,
  -0.703083;-0.371882;-0.606117;,
  0.002202;-0.366907;-0.930255;,
  -0.128728;-0.437381;-0.890015;,
  -0.263882;-0.368276;-0.891481;,
  0.503650;-0.370491;-0.780432;,
  0.371741;-0.439422;-0.817751;,
  0.259060;-0.367965;-0.893023;,
  0.844927;-0.373018;-0.383348;,
  0.754007;-0.443301;-0.484725;,
  0.700243;-0.371874;-0.609400;,
  0.917818;-0.373509;0.134537;,
  0.895707;-0.444645;0.000000;,
  0.917833;-0.373505;-0.134449;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000019;0.798713;0.601712;,
  0.563091;0.563091;0.604862;,
  -0.563077;0.563092;0.604874;,
  0.000019;-0.798728;-0.601693;,
  0.563092;-0.563077;-0.604874;,
  -0.563078;-0.563078;-0.604885;,
  0.798713;0.000019;0.601712;,
  -0.798728;0.000019;-0.601693;,
  0.659077;0.588342;-0.468477;,
  0.746005;0.665941;0.000000;,
  -0.596242;0.403164;0.694229;,
  0.659087;-0.588326;0.468484;,
  0.746019;-0.665924;-0.000000;,
  -0.659087;-0.588325;-0.468484;,
  0.588957;0.553568;0.588806;,
  -0.799575;0.501120;0.330996;,
  0.841176;0.000000;0.540762;,
  0.413744;0.000000;0.910393;,
  -0.143854;0.000000;0.989599;,
  -0.654651;0.000000;0.755931;,
  -0.959463;0.000000;0.281835;,
  -0.959463;0.000000;-0.281835;,
  -0.654651;0.000000;-0.755931;,
  -0.144149;0.000000;-0.989556;,
  0.413685;0.000000;-0.910420;,
  0.841302;0.000000;-0.540566;,
  1.000000;0.000000;0.000000;;
  205;
  4;0,17,20,14;,
  4;14,20,15,1;,
  4;20,16,3,15;,
  4;17,2,16,20;,
  4;2,8,21,16;,
  4;16,21,18,3;,
  4;169,19,5,170;,
  4;171,4,19,169;,
  4;4,11,22,19;,
  4;19,22,9,5;,
  4;22,10,7,9;,
  4;11,6,10,22;,
  4;6,13,23,10;,
  4;10,23,12,7;,
  4;172,14,1,173;,
  4;174,0,14,172;,
  4;1,15,24,173;,
  4;12,175,9,7;,
  4;175,170,5,9;,
  4;15,3,18,24;,
  4;6,11,25,13;,
  4;174,176,17,0;,
  4;176,8,2,17;,
  4;11,4,171,25;,
  4;26,43,46,40;,
  4;40,46,41,27;,
  4;46,42,29,41;,
  4;43,28,42,46;,
  4;28,34,47,42;,
  4;177,178,44,29;,
  4;178,45,31,44;,
  4;34,30,179,47;,
  4;30,37,48,179;,
  4;45,48,35,31;,
  4;48,36,33,35;,
  4;37,32,36,48;,
  4;32,39,49,36;,
  4;180,181,38,33;,
  4;181,40,27,38;,
  4;39,26,182,49;,
  4;27,41,50,38;,
  4;38,50,35,33;,
  4;50,44,31,35;,
  4;41,29,44,50;,
  4;32,37,51,39;,
  4;39,51,43,26;,
  4;51,34,28,43;,
  4;37,30,34,51;,
  3;85,86,87;,
  3;87,86,88;,
  3;86,100,88;,
  3;88,100,89;,
  3;100,99,89;,
  3;89,99,90;,
  3;99,98,90;,
  3;90,98,91;,
  3;98,97,91;,
  3;91,97,92;,
  3;97,96,92;,
  3;92,96,93;,
  3;96,95,93;,
  3;93,95,94;,
  3;52,68,53;,
  3;53,68,54;,
  3;54,68,55;,
  3;55,68,56;,
  3;56,68,57;,
  3;57,68,58;,
  3;58,183,59;,
  3;59,183,60;,
  3;60,183,61;,
  3;61,183,62;,
  3;62,183,63;,
  3;63,183,64;,
  3;64,184,65;,
  3;65,184,66;,
  3;66,184,67;,
  3;67,184,52;,
  4;52,70,69,67;,
  4;67,69,71,66;,
  4;66,71,72,65;,
  4;65,72,73,64;,
  4;64,73,74,63;,
  4;63,74,75,62;,
  4;62,75,76,61;,
  4;61,76,77,60;,
  4;60,77,78,59;,
  4;59,78,79,58;,
  4;58,79,80,57;,
  4;57,80,81,56;,
  4;56,81,82,55;,
  4;55,82,83,54;,
  4;54,83,84,53;,
  4;53,84,70,52;,
  4;70,86,85,69;,
  4;69,85,87,71;,
  4;71,87,88,72;,
  4;72,88,89,73;,
  4;73,89,90,74;,
  4;74,90,91,75;,
  4;75,91,92,76;,
  4;76,92,93,77;,
  4;77,93,94,78;,
  4;78,94,95,79;,
  4;79,95,96,80;,
  4;80,96,97,81;,
  4;81,97,98,82;,
  4;82,98,99,83;,
  4;83,99,100,84;,
  4;84,100,86,70;,
  4;101,136,134,103;,
  4;102,132,133,101;,
  4;103,104,105,102;,
  4;104,139,137,106;,
  4;106,107,108,105;,
  4;107,142,140,109;,
  4;109,110,111,108;,
  4;110,145,143,112;,
  4;112,113,114,111;,
  4;113,148,146,115;,
  4;115,116,117,114;,
  4;116,151,149,118;,
  4;118,119,120,117;,
  4;119,154,152,121;,
  4;121,122,123,120;,
  4;122,157,155,124;,
  4;124,125,126,123;,
  4;125,160,158,127;,
  4;127,128,129,126;,
  4;128,163,161,130;,
  4;130,131,132,129;,
  4;131,166,164,133;,
  4;135,138,139,134;,
  4;136,164,165,135;,
  4;138,141,142,137;,
  4;141,144,145,140;,
  4;144,147,148,143;,
  4;147,150,151,146;,
  4;150,153,154,149;,
  4;153,156,157,152;,
  4;156,159,160,155;,
  4;159,162,163,158;,
  4;162,165,166,161;,
  4;103,134,139,104;,
  4;106,137,142,107;,
  4;109,140,145,110;,
  4;112,143,148,113;,
  4;115,146,151,116;,
  4;118,149,154,119;,
  4;121,152,157,122;,
  4;124,155,160,125;,
  4;127,158,163,128;,
  4;130,161,166,131;,
  4;133,164,136,101;,
  3;117,120,114;,
  3;114,120,111;,
  3;111,120,108;,
  3;120,123,108;,
  3;108,123,105;,
  3;123,126,105;,
  3;105,126,102;,
  3;126,129,102;,
  3;102,129,132;,
  3;168,167,167;,
  3;167,167,167;,
  3;167,167,167;,
  3;167,167,167;,
  3;167,167,167;,
  3;167,167,167;,
  3;167,167,167;,
  3;167,167,167;,
  3;167,167,167;,
  3;101,103,102;,
  3;104,106,105;,
  3;107,109,108;,
  3;110,112,111;,
  3;113,115,114;,
  3;116,118,117;,
  3;119,121,120;,
  3;122,124,123;,
  3;125,127,126;,
  3;128,130,129;,
  3;131,133,132;,
  3;134,136,135;,
  3;137,139,138;,
  3;140,142,141;,
  3;143,145,144;,
  3;146,148,147;,
  3;149,151,150;,
  3;152,154,153;,
  3;155,157,156;,
  3;158,160,159;,
  3;161,163,162;,
  3;164,166,165;,
  4;135,185,186,138;,
  4;138,186,187,141;,
  4;141,187,188,144;,
  4;144,188,189,147;,
  4;147,189,190,150;,
  4;150,190,191,153;,
  4;153,191,192,156;,
  4;156,192,193,159;,
  4;159,193,194,162;,
  4;162,194,195,165;,
  4;165,195,185,135;;
 }
 MeshTextureCoords {
  267;
  0.375000;0.000000;,
  0.375000;0.125000;,
  0.500000;0.125000;,
  0.500000;0.000000;,
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
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.375000;0.750000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.500000;1.000000;,
  0.625000;1.000000;,
  0.375000;1.000000;,
  0.750000;0.125000;,
  0.750000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.000000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.125000;,
  0.250000;0.125000;,
  0.250000;0.000000;,
  0.250000;0.250000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.375000;0.125000;,
  0.500000;0.125000;,
  0.500000;0.000000;,
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
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.375000;0.750000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.500000;1.000000;,
  0.625000;1.000000;,
  0.375000;1.000000;,
  0.750000;0.125000;,
  0.750000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.000000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  0.125000;0.000000;,
  0.125000;0.125000;,
  0.250000;0.125000;,
  0.250000;0.000000;,
  0.250000;0.250000;,
  0.125000;0.250000;,
  0.750000;0.250000;,
  0.730970;0.154330;,
  0.730970;0.345670;,
  0.676780;0.426780;,
  0.676780;0.073220;,
  0.595670;0.480970;,
  0.595670;0.019030;,
  0.500000;0.500000;,
  0.500000;0.000000;,
  0.404330;0.480970;,
  0.404330;0.019030;,
  0.323220;0.426780;,
  0.323220;0.073220;,
  0.269030;0.345670;,
  0.269030;0.154330;,
  0.250000;0.250000;,
  0.250000;0.500000;,
  0.500000;1.000000;,
  0.281250;0.500000;,
  0.312500;0.500000;,
  0.343750;0.500000;,
  0.375000;0.500000;,
  0.406250;0.500000;,
  0.437500;0.500000;,
  0.468750;0.500000;,
  0.500000;0.500000;,
  0.531250;0.500000;,
  0.562500;0.500000;,
  0.593750;0.500000;,
  0.625000;0.500000;,
  0.656250;0.500000;,
  0.687500;0.500000;,
  0.718750;0.500000;,
  0.750000;0.500000;,
  0.730970;0.154330;,
  0.730970;0.154330;,
  0.750000;0.250000;,
  0.750000;0.250000;,
  0.730970;0.345670;,
  0.730970;0.345670;,
  0.676780;0.426780;,
  0.676780;0.426780;,
  0.595670;0.480970;,
  0.595670;0.480970;,
  0.500000;0.500000;,
  0.500000;0.500000;,
  0.404330;0.480970;,
  0.404330;0.480970;,
  0.323220;0.426780;,
  0.323220;0.426780;,
  0.269030;0.345670;,
  0.269030;0.345670;,
  0.250000;0.250000;,
  0.250000;0.250000;,
  0.269030;0.154330;,
  0.269030;0.154330;,
  0.323220;0.073220;,
  0.323220;0.073220;,
  0.404330;0.019030;,
  0.404330;0.019030;,
  0.500000;0.000000;,
  0.500000;0.000000;,
  0.595670;0.019030;,
  0.595670;0.019030;,
  0.676780;0.073220;,
  0.676780;0.073220;,
  0.375000;0.313600;,
  0.375070;0.687340;,
  0.380680;0.687110;,
  0.380680;0.313830;,
  0.622920;0.312500;,
  0.604360;0.312500;,
  0.607950;0.313830;,
  0.619320;0.313830;,
  0.392050;0.313830;,
  0.395640;0.312500;,
  0.377090;0.312500;,
  0.392050;0.687110;,
  0.403410;0.687110;,
  0.403410;0.313830;,
  0.414770;0.313830;,
  0.418370;0.312500;,
  0.399810;0.312500;,
  0.414770;0.687110;,
  0.426140;0.687110;,
  0.426140;0.313830;,
  0.437500;0.313830;,
  0.441100;0.312500;,
  0.422540;0.312500;,
  0.437500;0.687110;,
  0.448860;0.687110;,
  0.448860;0.313830;,
  0.460230;0.313830;,
  0.463820;0.312500;,
  0.445270;0.312500;,
  0.460230;0.687110;,
  0.471590;0.687110;,
  0.471590;0.313830;,
  0.482960;0.313830;,
  0.486550;0.312500;,
  0.467990;0.312500;,
  0.482960;0.687110;,
  0.494320;0.687110;,
  0.494320;0.313830;,
  0.505680;0.313830;,
  0.509280;0.312500;,
  0.490720;0.312500;,
  0.505680;0.687110;,
  0.517050;0.687110;,
  0.517050;0.313830;,
  0.528410;0.313830;,
  0.532010;0.312500;,
  0.513450;0.312500;,
  0.528410;0.687110;,
  0.539770;0.687110;,
  0.539770;0.313830;,
  0.551140;0.313830;,
  0.554730;0.312500;,
  0.536180;0.312500;,
  0.551140;0.687110;,
  0.562500;0.687110;,
  0.562500;0.313830;,
  0.573860;0.313830;,
  0.577460;0.312500;,
  0.558900;0.312500;,
  0.573860;0.687110;,
  0.585230;0.687110;,
  0.585230;0.313830;,
  0.596590;0.313830;,
  0.600190;0.312500;,
  0.581630;0.312500;,
  0.596590;0.687110;,
  0.607950;0.687110;,
  0.377090;0.688440;,
  0.395640;0.688440;,
  0.619320;0.687110;,
  0.604360;0.688440;,
  0.622920;0.688440;,
  0.399810;0.688440;,
  0.418370;0.688440;,
  0.422540;0.688440;,
  0.441100;0.688440;,
  0.445270;0.688440;,
  0.463820;0.688440;,
  0.467990;0.688440;,
  0.486550;0.688440;,
  0.490720;0.688440;,
  0.509280;0.688440;,
  0.513450;0.688440;,
  0.532010;0.688440;,
  0.536180;0.688440;,
  0.554730;0.688440;,
  0.558900;0.688440;,
  0.577460;0.688440;,
  0.581630;0.688440;,
  0.600190;0.688440;,
  0.377590;0.192190;,
  0.416450;0.252670;,
  0.377590;0.120310;,
  0.416450;0.059830;,
  0.481840;0.029970;,
  0.481840;0.282530;,
  0.553000;0.040200;,
  0.553000;0.272300;,
  0.607330;0.087280;,
  0.607330;0.225220;,
  0.627580;0.156250;,
  0.377590;0.879690;,
  0.416450;0.940170;,
  0.377590;0.807810;,
  0.416450;0.747330;,
  0.481840;0.717470;,
  0.481840;0.970030;,
  0.553000;0.727700;,
  0.553000;0.959800;,
  0.607330;0.774780;,
  0.607330;0.912720;,
  0.627580;0.843750;,
  0.607330;0.912720;,
  0.553000;0.959800;,
  0.481840;0.970030;,
  0.416450;0.940170;,
  0.377590;0.879690;,
  0.377590;0.807810;,
  0.416450;0.747330;,
  0.481840;0.717470;,
  0.553000;0.727700;,
  0.607330;0.774780;,
  0.627580;0.843750;;
 }
}
