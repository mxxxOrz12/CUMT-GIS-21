clear c;
clc;
format long g;
%已知点高程
Ha = 5.000;
Hb = 6.000;
%高差观测值
h = [1.359 2.009 0.363 0.640 0.657 1.000 1.650]';
%水准路线长度
s = [1 1 2 2 1 1 1.5];
%A矩阵
A = [1 -1 0 0 1 0 0;0 0 1 1 0 -1 0;0 0 0 0 1 1 -1;0 1 0 1 0 0 -1];
%A0矩阵
A0 = [0 0 0 Ha-Hb]';
%w矩阵
w = -(A*h+A0);
%定权
c = 1;
P = diag(c./s);
%P的逆矩阵
invP = inv(P);
Naa = A*invP*A';
K = inv(Naa)*w;

%观测值改正
V = invP*A'*K;
Hp = h+V;

Hp1 = Ha +Hp(1);
Hp2 = Hb -Hp(4);
Hp3 = Ha +Hp(2);

%输出结果
Hp1,Hp2,Hp3





