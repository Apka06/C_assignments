#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// gcc donut.c -lm -o donut
float acc(float x_vel, int *x_flag, float x_acc){
	if(*x_flag == 1){
		if (x_vel < 0.2){
			x_vel += x_acc;
		}
		else{
			*x_flag = 0;
			x_vel -= x_acc; 
		}
	}
	else{
		if (x_vel > -0.2){
			x_vel -= x_acc;
		}
		else{
			*x_flag = 1;
			x_vel += x_acc;
		}
	}
	return x_vel;
}

int k;
const float theta_spacing = 0.07;  //
const float phi_spacing = 0.02;    

int main() {
    float A = 0;
    int A_flag = 1;
    int *Ap = &A_flag;
    float A_vel = 0;
    float B = 0;
    int B_flag = 1;
    int *Bp = &B_flag;
    float B_vel = 0;
    float A_acc = 0.002;
    float B_acc = 0.00;
    float i, j;
    float zbuff[1760];  // Z buffer of 80 * 22
    char b[1760];       // chars of 80 * 22

    printf("\x1b[2J");  // clear screen
    for (;;) {
        memset(b, 32, 1760);
        memset(zbuff, 0, 7040);
        // theta goes around the cross-sectional circle of a torus
        for (j = 0; 6.28 > j; j += theta_spacing)
            // phi goes around the center of revolution of a torus
            for (i = 0; 6.28 > i; i += phi_spacing) {
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g -
                             l * d * n);
                if (22 > y && y > 0 && x > 0 && 80 > x && D > zbuff[o]) {
                    zbuff[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        printf("\x1b[H");
        for (k = 0; 1761 > k; k++)
            putchar(k % 80 ? b[k] : 10);
	A_vel = acc(A_vel, Ap, A_acc);
	B_vel = acc(B_vel, Bp, B_acc);
        A += A_vel;
        B += B_vel;
        usleep(1000 * 10);
    }

}
