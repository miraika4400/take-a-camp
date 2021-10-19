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
 296;
 2.73746;-4.19962;-3.31073;,
 -0.13524;-5.20492;-4.31683;,
 -0.13524;-1.32692;-5.60923;,
 3.74276;-1.32692;-4.31683;,
 -3.00794;-4.19962;-3.31073;,
 -4.01324;-1.32692;-4.31683;,
 -3.00794;1.54578;-3.31073;,
 -0.13524;2.55107;-4.31683;,
 2.73746;1.54578;-3.31073;,
 -0.13524;3.84428;-0.43803;,
 3.74276;2.55107;-0.43803;,
 -4.01324;2.55107;-0.43803;,
 -3.00794;1.54578;2.43467;,
 -0.13524;2.55107;3.43997;,
 2.73746;1.54578;2.43467;,
 -0.13524;-1.32692;4.73237;,
 3.74276;-1.32692;3.43997;,
 -4.01324;-1.32692;3.43997;,
 -3.00794;-4.19962;2.43467;,
 -0.13524;-5.20492;3.43997;,
 2.73746;-4.19962;2.43467;,
 -0.13524;-6.49812;-0.43803;,
 3.74276;-5.20492;-0.43803;,
 -4.01324;-5.20492;-0.43803;,
 -3.00794;-4.19962;-3.31073;,
 -0.13524;-5.20492;-4.31683;,
 2.73746;-4.19962;-3.31073;,
 -4.01324;-5.20492;-0.43803;,
 -5.30644;-1.32692;-0.43803;,
 -3.00794;-4.19962;2.43467;,
 -4.01324;-1.32692;3.43997;,
 -3.00794;1.54578;2.43467;,
 -4.01324;2.55107;-0.43803;,
 2.73746;-4.19962;2.43467;,
 3.74276;-5.20492;-0.43803;,
 5.03596;-1.32692;-0.43803;,
 3.74276;-1.32692;3.43997;,
 3.74276;2.55107;-0.43803;,
 2.73746;1.54578;2.43467;,
 2.02766;-15.82602;-3.49063;,
 -0.74794;-17.73613;-4.46163;,
 -0.74794;-10.36932;-5.71133;,
 2.99946;-10.36932;-4.46163;,
 -3.52444;-15.82602;-3.49063;,
 -4.49534;-10.36932;-4.46163;,
 -3.52444;-4.91272;-3.49063;,
 -0.74794;-3.00262;-4.46163;,
 2.02766;-4.91272;-3.49063;,
 -0.74794;-0.54683;-0.71423;,
 2.99946;-3.00262;-0.71423;,
 -4.49534;-3.00262;-0.71423;,
 -3.52444;-4.91272;2.06137;,
 -0.74794;-3.00262;3.03317;,
 2.02766;-4.91272;2.06137;,
 -0.74794;-10.36932;4.28207;,
 2.99946;-10.36932;3.03317;,
 -4.49534;-10.36932;3.03317;,
 -3.52444;-15.82602;2.06137;,
 -0.74794;-17.73613;3.03317;,
 2.02766;-15.82602;2.06137;,
 -0.74794;-20.19192;-0.71423;,
 2.99946;-17.73613;-0.71423;,
 -4.49534;-17.73613;-0.71423;,
 -3.52444;-15.82602;-3.49063;,
 -0.74794;-17.73613;-4.46163;,
 2.02766;-15.82602;-3.49063;,
 -4.49534;-17.73613;-0.71423;,
 -5.74504;-10.36932;-0.71423;,
 -3.52444;-15.82602;2.06137;,
 -4.49534;-10.36932;3.03317;,
 -3.52444;-4.91272;2.06137;,
 -4.49534;-3.00262;-0.71423;,
 2.02766;-15.82602;2.06137;,
 2.99946;-17.73613;-0.71423;,
 4.24826;-10.36932;-0.71423;,
 2.99946;-10.36932;3.03317;,
 2.99946;-3.00262;-0.71423;,
 2.02766;-4.91272;2.06137;,
 0.96716;-43.95692;-2.74063;,
 -0.53624;-44.51102;-3.26713;,
 -0.53624;-42.37242;-3.94353;,
 1.49366;-42.37242;-3.26713;,
 -2.04034;-43.95692;-2.74063;,
 -2.56604;-42.37242;-3.26713;,
 -2.04034;-40.78793;-2.74063;,
 -0.53624;-40.23383;-3.26713;,
 0.96716;-40.78793;-2.74063;,
 -0.53624;-39.52073;-1.23733;,
 1.49366;-40.23383;-1.23733;,
 -2.56604;-40.23383;-1.23733;,
 -2.04034;-40.78793;0.26677;,
 -0.53624;-40.23383;0.79247;,
 0.96716;-40.78793;0.26677;,
 -0.53624;-42.37242;1.46877;,
 1.49366;-42.37242;0.79247;,
 -2.56604;-42.37242;0.79247;,
 -2.04034;-43.95692;0.26677;,
 -0.53624;-44.51102;0.79247;,
 0.96716;-43.95692;0.26677;,
 -0.53624;-45.22423;-1.23733;,
 1.49366;-44.51102;-1.23733;,
 -2.56604;-44.51102;-1.23733;,
 -2.04034;-43.95692;-2.74063;,
 -0.53624;-44.51102;-3.26713;,
 0.96716;-43.95692;-2.74063;,
 -2.56604;-44.51102;-1.23733;,
 -3.24314;-42.37242;-1.23733;,
 -2.04034;-43.95692;0.26677;,
 -2.56604;-42.37242;0.79247;,
 -2.04034;-40.78793;0.26677;,
 -2.56604;-40.23383;-1.23733;,
 0.96716;-43.95692;0.26677;,
 1.49366;-44.51102;-1.23733;,
 2.16996;-42.37242;-1.23733;,
 1.49366;-42.37242;0.79247;,
 1.49366;-40.23383;-1.23733;,
 0.96716;-40.78793;0.26677;,
 2.48716;-3.11393;-7.48583;,
 -0.16624;-3.09803;-8.30273;,
 -0.13274;-0.82802;-8.92133;,
 3.19026;-0.75103;-7.97293;,
 -2.90914;-3.15752;-7.87503;,
 -3.55874;-0.80622;-8.46013;,
 -2.80794;1.30478;-8.71963;,
 -0.12184;2.57948;-9.32473;,
 2.46286;1.34828;-8.33963;,
 -0.14944;3.80238;-9.02513;,
 3.75026;2.79798;-5.43003;,
 -4.51374;2.73018;-6.02603;,
 -0.22904;-4.66082;-7.31343;,
 -4.51714;-4.03722;-5.49783;,
 -2.90914;-3.15752;-7.87503;,
 -0.16624;-3.09803;-8.30273;,
 3.74686;-3.96943;-4.90103;,
 2.48716;-3.11393;-7.48583;,
 -4.51714;-4.03722;-5.49783;,
 -5.91494;-0.65642;-5.55983;,
 -4.51374;2.73018;-6.02603;,
 3.74686;-3.96943;-4.90103;,
 5.10456;-0.56602;-4.76463;,
 3.75026;2.79798;-5.43003;,
 -1.38914;-41.70953;-5.18233;,
 -2.00774;-36.86313;-5.12543;,
 -0.44414;-42.01253;-5.73813;,
 -0.44414;-37.14513;-6.23863;,
 -1.98844;-31.90033;-5.52963;,
 -0.44414;-32.20002;-6.75513;,
 -2.93014;-22.05182;-5.46603;,
 -0.44414;-22.29292;-6.88313;,
 -4.46274;-12.27612;-6.40103;,
 -0.44414;-12.39332;-7.39293;,
 -4.76574;-7.34182;-6.71243;,
 -0.44414;-7.45392;-8.23243;,
 -4.81264;-2.37652;-6.65463;,
 -0.44414;-2.50293;-8.45173;,
 -3.64574;-36.71573;-1.25993;,
 -4.36984;-31.82923;-1.47673;,
 -2.92094;-41.62332;-2.46863;,
 -5.57344;-22.04432;-1.91033;,
 -5.96184;-12.16142;-2.34893;,
 -6.15604;-7.22042;-2.56823;,
 -6.35024;-2.27862;-2.78753;,
 3.92516;-2.37652;-6.65463;,
 5.46286;-2.27862;-2.78753;,
 3.87746;-7.34182;-6.71243;,
 3.57526;-12.27612;-6.40103;,
 2.04266;-22.05182;-5.46603;,
 1.10106;-31.90033;-5.52963;,
 1.12026;-36.86313;-5.12543;,
 0.50176;-41.70953;-5.18233;,
 2.03346;-41.62332;-2.46863;,
 5.26866;-7.22042;-2.56823;,
 5.07446;-12.16142;-2.34893;,
 4.68606;-22.04432;-1.91033;,
 3.48236;-31.82923;-1.47673;,
 2.75756;-36.71573;-1.25993;,
 5.26866;-7.22042;-2.56823;,
 5.46286;-2.27862;-2.78753;,
 4.03486;-7.05053;2.57867;,
 3.80716;-2.11032;2.35937;,
 2.97176;-6.92492;5.93017;,
 2.73746;-2.08442;3.91787;,
 4.68606;-22.04432;-1.91033;,
 4.01476;-21.99992;3.24157;,
 3.48236;-31.82923;-1.47673;,
 2.77766;-31.78482;3.67597;,
 2.67466;-21.82332;3.91207;,
 1.96406;-31.70192;4.10877;,
 5.07446;-12.16142;-2.34893;,
 4.40396;-15.63592;2.75107;,
 4.68606;-22.04432;-1.91033;,
 4.01476;-21.99992;3.24157;,
 2.61686;-15.48942;5.42457;,
 2.67466;-21.82332;3.91207;,
 3.48236;-31.82923;-1.47673;,
 2.77766;-31.78482;3.67597;,
 2.75756;-36.71573;-1.25993;,
 2.21596;-36.67142;3.89277;,
 1.96406;-31.70192;4.10877;,
 1.60826;-36.58693;4.14647;,
 5.26866;-7.22042;-2.56823;,
 4.03486;-7.05053;2.57867;,
 5.07446;-12.16142;-2.34893;,
 4.40396;-15.63592;2.75107;,
 2.97176;-6.92492;5.93017;,
 2.61686;-15.48942;5.42457;,
 2.75756;-36.71573;-1.25993;,
 2.21596;-36.67142;3.89277;,
 2.03346;-41.62332;-2.46863;,
 2.00926;-41.68772;1.14987;,
 1.25336;-41.75143;1.18747;,
 1.60826;-36.58693;4.14647;,
 -3.86004;-6.92492;5.93017;,
 -3.62484;-2.08442;3.91787;,
 -4.92224;-7.05053;2.57867;,
 -4.69544;-2.11032;2.35937;,
 -6.35024;-2.27862;-2.78753;,
 -6.15604;-7.22042;-2.56823;,
 -2.85224;-31.70192;4.10877;,
 -3.56294;-21.82332;3.91207;,
 -3.66504;-31.78482;3.67597;,
 -4.36984;-31.82923;-1.47673;,
 -4.90294;-21.99992;3.24157;,
 -5.57344;-22.04432;-1.91033;,
 -3.50434;-15.48942;5.42457;,
 -5.29134;-15.63592;2.75107;,
 -3.56294;-21.82332;3.91207;,
 -4.90294;-21.99992;3.24157;,
 -5.57344;-22.04432;-1.91033;,
 -5.96184;-12.16142;-2.34893;,
 -2.49654;-36.58693;4.14647;,
 -2.85224;-31.70192;4.10877;,
 -3.10334;-36.67142;3.89277;,
 -3.66504;-31.78482;3.67597;,
 -3.64574;-36.71573;-1.25993;,
 -4.36984;-31.82923;-1.47673;,
 -3.50434;-15.48942;5.42457;,
 -3.86004;-6.92492;5.93017;,
 -5.29134;-15.63592;2.75107;,
 -4.92224;-7.05053;2.57867;,
 -5.96184;-12.16142;-2.34893;,
 -6.15604;-7.22042;-2.56823;,
 -2.49654;-36.58693;4.14647;,
 -3.10334;-36.67142;3.89277;,
 -2.14074;-41.75143;1.18747;,
 -3.64574;-36.71573;-1.25993;,
 -2.89744;-41.68772;1.14987;,
 -2.92094;-41.62332;-2.46863;,
 2.97176;-6.92492;5.93017;,
 2.73746;-2.08442;3.91787;,
 -0.76054;-2.01152;4.88467;,
 -0.71864;-6.88142;5.88327;,
 -3.62484;-2.08442;3.91787;,
 -3.86004;-6.92492;5.93017;,
 -0.16954;-6.88142;5.88327;,
 -0.12684;-2.01152;4.88467;,
 -3.56294;-21.82332;3.91207;,
 -2.85224;-31.70192;4.10877;,
 -0.38214;-31.72953;4.10957;,
 -0.29764;-21.82332;3.91207;,
 1.96406;-31.70192;4.10877;,
 2.67466;-21.82332;3.91207;,
 -0.59064;-21.82332;3.91207;,
 -0.50524;-31.72953;4.10957;,
 2.67466;-21.82332;3.91207;,
 2.61686;-15.48942;5.42457;,
 -0.67594;-15.46022;5.37687;,
 -0.59064;-21.82332;3.91207;,
 -3.50434;-15.48942;5.42457;,
 -3.56294;-21.82332;3.91207;,
 -0.29764;-21.82332;3.91207;,
 -0.21224;-15.46022;5.37687;,
 -2.85224;-31.70192;4.10877;,
 -2.49654;-36.58693;4.14647;,
 -0.42484;-36.62793;4.13637;,
 -0.38214;-31.72953;4.10957;,
 1.60826;-36.58693;4.14647;,
 1.96406;-31.70192;4.10877;,
 -0.50524;-31.72953;4.10957;,
 -0.46254;-36.62793;4.13637;,
 2.61686;-15.48942;5.42457;,
 2.97176;-6.92492;5.93017;,
 -0.71864;-6.88142;5.88327;,
 -0.67594;-15.46022;5.37687;,
 -3.86004;-6.92492;5.93017;,
 -3.50434;-15.48942;5.42457;,
 -0.21224;-15.46022;5.37687;,
 -0.16954;-6.88142;5.88327;,
 -2.49654;-36.58693;4.14647;,
 -2.14074;-41.75143;1.18747;,
 -0.46754;-41.80653;1.18167;,
 -0.42484;-36.62793;4.13637;,
 1.25336;-41.75143;1.18747;,
 1.60826;-36.58693;4.14647;,
 -0.46254;-36.62793;4.13637;,
 -0.41984;-41.80653;1.18167;;
 
 192;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;2,5,6,7;,
 4;3,2,7,8;,
 4;8,7,9,10;,
 4;7,6,11,9;,
 4;9,11,12,13;,
 4;10,9,13,14;,
 4;14,13,15,16;,
 4;13,12,17,15;,
 4;15,17,18,19;,
 4;16,15,19,20;,
 4;20,19,21,22;,
 4;19,18,23,21;,
 4;21,23,24,25;,
 4;22,21,25,26;,
 4;4,27,28,5;,
 4;27,29,30,28;,
 4;28,30,31,32;,
 4;5,28,32,6;,
 4;33,34,35,36;,
 4;34,0,3,35;,
 4;35,3,8,37;,
 4;36,35,37,38;,
 4;39,40,41,42;,
 4;40,43,44,41;,
 4;41,44,45,46;,
 4;42,41,46,47;,
 4;47,46,48,49;,
 4;46,45,50,48;,
 4;48,50,51,52;,
 4;49,48,52,53;,
 4;53,52,54,55;,
 4;52,51,56,54;,
 4;54,56,57,58;,
 4;55,54,58,59;,
 4;59,58,60,61;,
 4;58,57,62,60;,
 4;60,62,63,64;,
 4;61,60,64,65;,
 4;43,66,67,44;,
 4;66,68,69,67;,
 4;67,69,70,71;,
 4;44,67,71,45;,
 4;72,73,74,75;,
 4;73,39,42,74;,
 4;74,42,47,76;,
 4;75,74,76,77;,
 4;78,79,80,81;,
 4;79,82,83,80;,
 4;80,83,84,85;,
 4;81,80,85,86;,
 4;86,85,87,88;,
 4;85,84,89,87;,
 4;87,89,90,91;,
 4;88,87,91,92;,
 4;92,91,93,94;,
 4;91,90,95,93;,
 4;93,95,96,97;,
 4;94,93,97,98;,
 4;98,97,99,100;,
 4;97,96,101,99;,
 4;99,101,102,103;,
 4;100,99,103,104;,
 4;82,105,106,83;,
 4;105,107,108,106;,
 4;106,108,109,110;,
 4;83,106,110,84;,
 4;111,112,113,114;,
 4;112,78,81,113;,
 4;113,81,86,115;,
 4;114,113,115,116;,
 4;117,118,119,120;,
 4;118,121,122,119;,
 4;119,122,123,124;,
 4;120,119,124,125;,
 4;125,124,126,127;,
 4;124,123,128,126;,
 4;129,130,131,132;,
 4;133,129,132,134;,
 4;121,135,136,122;,
 4;122,136,137,123;,
 4;138,117,120,139;,
 4;139,120,125,140;,
 3;141,142,143;,
 3;143,142,144;,
 3;142,145,144;,
 3;144,145,146;,
 3;145,147,146;,
 3;146,147,148;,
 3;147,149,148;,
 3;148,149,150;,
 3;149,151,150;,
 3;150,151,152;,
 3;151,153,152;,
 3;153,154,152;,
 3;155,156,157;,
 3;156,158,157;,
 3;157,158,141;,
 3;158,159,141;,
 3;159,160,141;,
 3;160,161,141;,
 3;161,153,149;,
 3;153,151,149;,
 3;149,147,161;,
 3;161,147,142;,
 3;147,145,142;,
 3;142,141,161;,
 3;162,163,164;,
 3;164,163,165;,
 3;165,163,166;,
 3;166,163,167;,
 3;167,163,168;,
 3;168,163,169;,
 3;169,163,170;,
 3;163,171,170;,
 3;171,172,170;,
 3;172,173,170;,
 3;173,174,170;,
 3;174,175,170;,
 3;154,162,152;,
 3;162,164,152;,
 3;152,164,150;,
 3;164,165,150;,
 3;150,165,148;,
 3;165,166,148;,
 3;148,166,146;,
 3;166,167,146;,
 3;146,167,144;,
 3;167,168,144;,
 3;144,168,143;,
 3;168,169,143;,
 3;176,177,178;,
 3;177,179,178;,
 3;178,179,180;,
 3;179,181,180;,
 3;182,183,184;,
 3;184,183,185;,
 3;183,186,185;,
 3;186,187,185;,
 3;188,189,190;,
 3;190,189,191;,
 3;189,192,191;,
 3;192,193,191;,
 3;194,195,196;,
 3;196,195,197;,
 3;195,198,197;,
 3;198,199,197;,
 3;200,201,202;,
 3;202,201,203;,
 3;201,204,203;,
 3;204,205,203;,
 3;206,207,208;,
 3;208,207,209;,
 3;209,207,210;,
 3;207,211,210;,
 3;212,213,214;,
 3;213,215,214;,
 3;215,216,214;,
 3;216,217,214;,
 3;218,219,220;,
 3;220,219,221;,
 3;219,222,221;,
 3;222,223,221;,
 3;224,225,226;,
 3;226,225,227;,
 3;227,225,228;,
 3;225,229,228;,
 3;230,231,232;,
 3;231,233,232;,
 3;232,233,234;,
 3;233,235,234;,
 3;236,237,238;,
 3;237,239,238;,
 3;238,239,240;,
 3;239,241,240;,
 3;242,243,244;,
 3;243,245,244;,
 3;244,245,246;,
 3;245,247,246;,
 4;248,249,250,251;,
 4;252,253,254,255;,
 4;256,257,258,259;,
 4;260,261,262,263;,
 4;264,265,266,267;,
 4;268,269,270,271;,
 4;272,273,274,275;,
 4;276,277,278,279;,
 4;280,281,282,283;,
 4;284,285,286,287;,
 4;288,289,290,291;,
 4;292,293,294,295;;
 
 MeshMaterialList {
  18;
  192;
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15;;
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
  192;
  0.577361;-0.577361;-0.577328;,
  -0.577361;-0.577361;-0.577328;,
  0.577361;0.577361;-0.577328;,
  -0.577361;0.577361;-0.577328;,
  0.577330;0.577330;0.577391;,
  -0.577330;0.577330;0.577391;,
  0.577330;-0.577330;0.577391;,
  -0.577330;-0.577330;0.577391;,
  0.707107;0.707107;0.000017;,
  -0.707059;-0.000000;0.707155;,
  -0.000000;-0.707059;0.707155;,
  0.707059;-0.000000;0.707155;,
  -0.707107;-0.707107;0.000017;,
  0.707107;-0.707107;0.000017;,
  -0.000000;-0.707116;-0.707098;,
  -0.707115;-0.000000;-0.707098;,
  -0.000000;0.707115;-0.707098;,
  0.707115;-0.000000;-0.707098;,
  -0.707107;0.707107;0.000017;,
  -0.000000;0.707059;0.707155;,
  -0.000000;-0.000000;-1.000000;,
  -0.000000;1.000000;0.000017;,
  -0.000000;-0.000000;1.000000;,
  -0.000000;-1.000000;0.000017;,
  -1.000000;-0.000000;0.000017;,
  1.000000;-0.000000;0.000017;,
  0.657008;-0.369769;-0.656971;,
  -0.656983;-0.369800;-0.656979;,
  0.657008;0.369771;-0.656971;,
  -0.656982;0.369802;-0.656979;,
  0.657001;0.369743;0.656993;,
  -0.656976;0.369774;0.657001;,
  0.657001;-0.369741;0.656994;,
  -0.656976;-0.369772;0.657002;,
  0.898535;0.388325;-0.204542;,
  -0.707087;0.000002;0.707126;,
  0.000033;-0.498913;0.866652;,
  0.707113;0.000002;0.707101;,
  -0.762901;-0.439220;0.474414;,
  0.898540;-0.388287;0.204595;,
  0.000032;-0.498959;-0.866625;,
  -0.707110;0.000002;-0.707104;,
  0.000032;0.498961;-0.866625;,
  0.707135;0.000002;-0.707079;,
  -0.762903;0.439261;-0.474372;,
  -0.474391;0.439218;0.762916;,
  0.000031;0.000002;-1.000000;,
  0.538004;0.648925;-0.538004;,
  0.000031;0.000002;1.000000;,
  0.538051;-0.648847;0.538051;,
  -1.000000;0.000002;0.000027;,
  1.000000;0.000002;0.000027;,
  0.585081;-0.561568;-0.585082;,
  -0.585049;-0.561585;-0.585098;,
  0.585076;0.561579;-0.585077;,
  -0.585044;0.561596;-0.585093;,
  0.585052;0.561559;0.585120;,
  -0.585020;0.561576;0.585136;,
  0.585057;-0.561548;0.585126;,
  -0.585025;-0.561565;0.585141;,
  0.720416;0.693542;-0.000050;,
  -0.707016;0.000001;0.707198;,
  0.000040;-0.693474;0.720482;,
  0.707050;0.000001;0.707164;,
  -0.720395;-0.693564;-0.000050;,
  0.720429;-0.693529;-0.000050;,
  0.000040;-0.693533;-0.720425;,
  -0.707077;0.000001;-0.707136;,
  0.000040;0.693546;-0.720412;,
  0.707111;0.000001;-0.707103;,
  -0.720382;0.693577;-0.000050;,
  0.000040;0.693487;0.720469;,
  0.000039;0.000001;-1.000000;,
  0.000040;1.000000;-0.000050;,
  0.000039;0.000001;1.000000;,
  0.000040;-1.000000;-0.000050;,
  -1.000000;0.000001;-0.000049;,
  1.000000;0.000001;-0.000049;,
  0.510049;-0.447873;-0.734343;,
  -0.392673;-0.453130;-0.800301;,
  0.601966;0.184935;-0.776811;,
  -0.486805;0.179151;-0.854942;,
  0.713911;0.312200;-0.626787;,
  -0.507782;-0.529237;-0.679754;,
  0.607481;-0.522585;-0.598224;,
  0.066221;-0.501241;-0.862770;,
  -0.489075;-0.130892;-0.862365;,
  0.069767;0.165905;-0.983671;,
  0.609613;-0.125031;-0.782776;,
  -0.620851;0.304981;-0.722171;,
  0.072214;-0.184077;-0.980256;,
  0.558115;0.389428;-0.732703;,
  0.056582;-0.704535;-0.707410;,
  -0.777473;-0.060611;-0.625989;,
  0.859925;-0.051884;-0.507776;,
  0.872804;-0.096425;-0.478452;,
  -0.822916;-0.081098;-0.562345;,
  0.591756;-0.013602;-0.806002;,
  -0.591698;-0.027150;-0.805702;,
  0.957442;-0.065582;-0.281075;,
  -0.984334;-0.064949;-0.163912;,
  0.909755;-0.102420;-0.402314;,
  -0.977019;-0.134119;-0.165668;,
  -0.554210;-0.069591;-0.829463;,
  -0.000032;-0.044251;-0.999020;,
  0.743664;-0.099941;-0.661041;,
  -0.000053;-0.081918;-0.996639;,
  -0.721909;-0.089976;-0.686113;,
  -0.982956;-0.086237;-0.162359;,
  0.987996;-0.084041;-0.129619;,
  0.966875;-0.031282;-0.253325;,
  -0.985320;-0.029253;-0.168190;,
  -0.663884;-0.112078;-0.739389;,
  -0.000016;-0.098524;-0.995135;,
  0.886941;-0.144457;-0.438711;,
  0.697976;-0.066347;-0.713041;,
  -0.586071;-0.049136;-0.808768;,
  -0.626305;-0.064429;-0.776911;,
  -0.993315;-0.105318;0.047269;,
  0.990320;-0.130440;0.047449;,
  0.602962;-0.059005;-0.795585;,
  -0.973458;-0.048187;-0.223736;,
  -0.302308;-0.075621;-0.950206;,
  -0.000010;-0.068189;-0.997672;,
  0.621872;-0.068552;-0.780113;,
  0.741938;-0.081970;-0.665438;,
  -0.601341;-0.075688;-0.795399;,
  -0.740883;-0.080414;-0.666803;,
  -0.985202;-0.156411;0.070090;,
  0.986104;-0.141557;0.086958;,
  0.912870;0.128042;0.387652;,
  0.966338;0.025305;0.256027;,
  -0.896545;0.060638;0.438784;,
  -0.952311;0.046789;0.301522;,
  -0.804840;-0.157067;0.572331;,
  -0.874717;-0.061089;0.480769;,
  0.858423;-0.095340;0.504005;,
  0.816491;-0.078000;0.572066;,
  0.951126;-0.011491;0.308591;,
  -0.912198;-0.021725;0.409174;,
  -0.719873;-0.204248;0.663374;,
  0.726553;-0.231562;0.646915;,
  -0.008102;0.435145;0.900324;,
  0.998997;-0.044385;0.005891;,
  0.503864;0.303003;0.808895;,
  0.703430;0.103465;0.703193;,
  -0.710374;0.196330;0.675888;,
  -0.920113;0.049667;0.388491;,
  -0.501667;-0.117219;0.857082;,
  -0.270618;-0.005158;0.962673;,
  0.272904;-0.092681;0.957567;,
  0.270361;-0.005134;0.962745;,
  0.455523;-0.126489;0.881192;,
  -0.462218;-0.136211;0.876243;,
  -0.174941;-0.263020;0.948797;,
  0.174714;-0.263001;0.948844;,
  -0.110243;-0.207350;0.972035;,
  0.124033;-0.492971;0.861160;,
  0.130713;0.293781;0.946893;,
  0.059375;0.119783;0.991023;,
  -0.130712;0.293801;0.946887;,
  -0.059374;0.119794;0.991022;,
  0.004034;-0.105063;0.994457;,
  0.001161;0.013241;0.999912;,
  -0.004033;-0.105061;0.994458;,
  -0.001161;0.013243;0.999912;,
  -0.011157;-0.144072;0.989504;,
  0.011158;-0.144072;0.989504;,
  -0.003670;-0.253664;0.967285;,
  0.003670;-0.253664;0.967285;,
  -0.009460;-0.496434;0.868023;,
  0.009461;-0.496434;0.868023;,
  -0.537951;0.649012;-0.537951;,
  -0.537998;0.648934;0.537998;,
  -0.762900;0.439221;0.474414;,
  0.538051;0.648847;0.538051;,
  0.474438;0.439173;0.762913;,
  -0.537998;-0.648934;0.537998;,
  -0.537951;-0.649012;-0.537951;,
  -0.762904;-0.439259;-0.474372;,
  0.538004;-0.648925;-0.538004;,
  -0.452968;0.383717;-0.804725;,
  -0.821019;-0.014399;0.570719;,
  0.240844;-0.062875;-0.968525;,
  0.585879;-0.049132;-0.808908;,
  0.601136;-0.075707;-0.795553;,
  0.553926;-0.069568;-0.829655;,
  0.971865;-0.027815;0.233891;,
  0.083931;-0.480728;0.872844;,
  -0.361431;-0.419353;0.832773;,
  -0.965663;-0.238205;0.103699;,
  -0.989126;-0.147021;0.003807;;
  192;
  4;0,14,20,17;,
  4;14,1,15,20;,
  4;20,15,3,16;,
  4;17,20,16,2;,
  4;2,16,21,8;,
  4;16,3,18,21;,
  4;21,18,5,19;,
  4;8,21,19,4;,
  4;4,19,22,11;,
  4;19,5,9,22;,
  4;22,9,7,10;,
  4;11,22,10,6;,
  4;6,10,23,13;,
  4;10,7,12,23;,
  4;23,12,1,14;,
  4;13,23,14,0;,
  4;1,12,24,15;,
  4;12,7,9,24;,
  4;24,9,5,18;,
  4;15,24,18,3;,
  4;6,13,25,11;,
  4;13,0,17,25;,
  4;25,17,2,8;,
  4;11,25,8,4;,
  4;26,40,46,43;,
  4;40,27,41,46;,
  4;46,41,29,42;,
  4;43,46,42,28;,
  4;28,42,47,34;,
  4;42,29,44,172;,
  4;173,174,31,45;,
  4;175,175,176,30;,
  4;30,176,48,37;,
  4;45,31,35,48;,
  4;48,35,33,36;,
  4;37,48,36,32;,
  4;32,36,49,39;,
  4;36,33,38,177;,
  4;178,179,27,40;,
  4;180,180,40,26;,
  4;27,179,50,41;,
  4;38,33,35,50;,
  4;50,35,31,174;,
  4;41,50,44,29;,
  4;32,39,51,37;,
  4;39,26,43,51;,
  4;51,43,28,34;,
  4;37,51,34,30;,
  4;52,66,72,69;,
  4;66,53,67,72;,
  4;72,67,55,68;,
  4;69,72,68,54;,
  4;54,68,73,60;,
  4;68,55,70,73;,
  4;73,70,57,71;,
  4;60,73,71,56;,
  4;56,71,74,63;,
  4;71,57,61,74;,
  4;74,61,59,62;,
  4;63,74,62,58;,
  4;58,62,75,65;,
  4;62,59,64,75;,
  4;75,64,53,66;,
  4;65,75,66,52;,
  4;53,64,76,67;,
  4;64,59,61,76;,
  4;76,61,57,70;,
  4;67,76,70,55;,
  4;58,65,77,63;,
  4;65,52,69,77;,
  4;77,69,54,60;,
  4;63,77,60,56;,
  4;78,85,90,88;,
  4;85,79,86,90;,
  4;90,86,81,87;,
  4;88,90,87,80;,
  4;80,87,91,82;,
  4;87,81,89,181;,
  4;92,83,79,85;,
  4;84,92,85,78;,
  4;79,83,93,86;,
  4;86,93,89,81;,
  4;84,78,88,94;,
  4;94,88,80,82;,
  3;96,127,103;,
  3;103,127,126;,
  3;127,117,126;,
  3;126,117,116;,
  3;117,107,116;,
  3;116,107,106;,
  3;107,112,106;,
  3;106,112,113;,
  3;112,122,113;,
  3;113,122,123;,
  3;122,98,123;,
  3;98,104,123;,
  3;128,118,102;,
  3;118,108,102;,
  3;102,108,96;,
  3;108,111,96;,
  3;111,121,96;,
  3;121,100,96;,
  3;100,98,112;,
  3;182,182,182;,
  3;112,107,100;,
  3;100,107,127;,
  3;107,117,127;,
  3;127,96,100;,
  3;97,99,124;,
  3;124,99,114;,
  3;114,99,105;,
  3;105,99,115;,
  3;115,99,125;,
  3;125,99,95;,
  3;95,99,101;,
  3;99,120,101;,
  3;120,110,101;,
  3;110,109,101;,
  3;109,119,101;,
  3;119,129,101;,
  3;104,97,123;,
  3;97,124,123;,
  3;123,124,113;,
  3;124,183,113;,
  3;113,183,106;,
  3;114,105,106;,
  3;106,105,184;,
  3;105,115,184;,
  3;184,115,185;,
  3;115,125,185;,
  3;185,125,186;,
  3;125,95,186;,
  3;187,99,131;,
  3;99,130,131;,
  3;131,130,145;,
  3;130,144,145;,
  3;109,136,119;,
  3;119,136,137;,
  3;136,150,137;,
  3;150,151,137;,
  3;110,138,109;,
  3;109,138,136;,
  3;138,152,136;,
  3;152,150,136;,
  3;119,137,129;,
  3;129,137,141;,
  3;137,151,141;,
  3;151,155,141;,
  3;187,131,110;,
  3;110,131,138;,
  3;131,145,138;,
  3;145,152,138;,
  3;129,141,101;,
  3;101,141,143;,
  3;188,141,157;,
  3;141,155,157;,
  3;147,146,133;,
  3;146,132,133;,
  3;132,100,133;,
  3;100,121,133;,
  3;149,148,135;,
  3;135,148,118;,
  3;148,134,189;,
  3;134,108,118;,
  3;153,139,148;,
  3;148,139,134;,
  3;134,139,108;,
  3;139,111,108;,
  3;154,149,140;,
  3;149,135,140;,
  3;140,135,128;,
  3;135,118,128;,
  3;153,147,139;,
  3;147,133,139;,
  3;139,133,111;,
  3;133,121,111;,
  3;154,140,156;,
  3;140,128,190;,
  3;156,142,142;,
  3;128,102,191;,
  4;145,144,158,159;,
  4;146,161,161,160;,
  4;148,149,163,162;,
  4;151,150,164,165;,
  4;150,152,166,164;,
  4;153,148,162,167;,
  4;149,154,168,163;,
  4;155,151,165,169;,
  4;152,145,159,166;,
  4;161,153,167,161;,
  4;154,156,170,168;,
  4;157,155,169,171;;
 }
 MeshTextureCoords {
  296;
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.125000;,
  0.375000;0.125000;,
  0.625000;0.000000;,
  0.625000;0.125000;,
  0.625000;0.250000;,
  0.500000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.375000;,
  0.375000;0.375000;,
  0.625000;0.375000;,
  0.625000;0.500000;,
  0.500000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.625000;,
  0.375000;0.625000;,
  0.625000;0.625000;,
  0.625000;0.750000;,
  0.500000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.875000;,
  0.375000;0.875000;,
  0.625000;0.875000;,
  0.625000;1.000000;,
  0.500000;1.000000;,
  0.375000;1.000000;,
  0.750000;0.000000;,
  0.750000;0.125000;,
  0.875000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.250000;,
  0.750000;0.250000;,
  0.125000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.125000;,
  0.125000;0.125000;,
  0.250000;0.250000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.125000;,
  0.375000;0.125000;,
  0.625000;0.000000;,
  0.625000;0.125000;,
  0.625000;0.250000;,
  0.500000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.375000;,
  0.375000;0.375000;,
  0.625000;0.375000;,
  0.625000;0.500000;,
  0.500000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.625000;,
  0.375000;0.625000;,
  0.625000;0.625000;,
  0.625000;0.750000;,
  0.500000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.875000;,
  0.375000;0.875000;,
  0.625000;0.875000;,
  0.625000;1.000000;,
  0.500000;1.000000;,
  0.375000;1.000000;,
  0.750000;0.000000;,
  0.750000;0.125000;,
  0.875000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.250000;,
  0.750000;0.250000;,
  0.125000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.125000;,
  0.125000;0.125000;,
  0.250000;0.250000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.125000;,
  0.375000;0.125000;,
  0.625000;0.000000;,
  0.625000;0.125000;,
  0.625000;0.250000;,
  0.500000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.375000;,
  0.375000;0.375000;,
  0.625000;0.375000;,
  0.625000;0.500000;,
  0.500000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.625000;,
  0.375000;0.625000;,
  0.625000;0.625000;,
  0.625000;0.750000;,
  0.500000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.875000;,
  0.375000;0.875000;,
  0.625000;0.875000;,
  0.625000;1.000000;,
  0.500000;1.000000;,
  0.375000;1.000000;,
  0.750000;0.000000;,
  0.750000;0.125000;,
  0.875000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.250000;,
  0.750000;0.250000;,
  0.125000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.125000;,
  0.125000;0.125000;,
  0.250000;0.250000;,
  0.125000;0.250000;,
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.125000;,
  0.375000;0.125000;,
  0.625000;0.000000;,
  0.625000;0.125000;,
  0.625000;0.250000;,
  0.500000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.375000;,
  0.375000;0.375000;,
  0.625000;0.375000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.625000;1.000000;,
  0.500000;1.000000;,
  0.375000;0.875000;,
  0.375000;1.000000;,
  0.750000;0.000000;,
  0.750000;0.125000;,
  0.750000;0.250000;,
  0.250000;0.000000;,
  0.250000;0.125000;,
  0.250000;0.250000;,
  0.625000;0.000000;,
  0.625000;0.031250;,
  0.500000;0.000000;,
  0.500000;0.031250;,
  0.625000;0.062500;,
  0.500000;0.062500;,
  0.625000;0.125000;,
  0.500000;0.125000;,
  0.625000;0.187500;,
  0.500000;0.187500;,
  0.625000;0.218750;,
  0.500000;0.218750;,
  0.625000;0.250000;,
  0.500000;0.250000;,
  0.875000;0.031250;,
  0.875000;0.062500;,
  0.875000;0.000000;,
  0.875000;0.125000;,
  0.875000;0.187500;,
  0.875000;0.218750;,
  0.875000;0.250000;,
  0.375000;0.250000;,
  0.125000;0.250000;,
  0.375000;0.218750;,
  0.375000;0.187500;,
  0.375000;0.125000;,
  0.375000;0.062500;,
  0.375000;0.031250;,
  0.375000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.218750;,
  0.125000;0.187500;,
  0.125000;0.125000;,
  0.125000;0.062500;,
  0.125000;0.031250;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;;
 }
}
