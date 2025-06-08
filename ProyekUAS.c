#include <stdio.h>
#include <math.h>

// Definisi konstanta fisika yang digunakan dalam perhitungan
#define m 68.1      // Massa objek (kg)
#define g 9.8       // Percepatan gravitasi (m/s^2)
#define c 12.5      // Koefisien hambat udara (kg/s)

/**
 * Fungsi dvdt(v) digunakan untuk menghitung turunan kecepatan terhadap waktu (dv/dt)
 * berdasarkan persamaan diferensial dv/dt = g - (c/m) * v^2.
 */
double dvdt(double v) {
    return g - (c/m) * v * v;
}

int main() {
    double v = 0.0;            // Kecepatan awal (m/s)
    double t = 0.0;            // Waktu awal (detik)
    double dt = 0.1;           // Langkah waktu (detik)
    double vt_theoretical;     // Kecepatan terminal secara teoritis
    double k1, k2, k3, k4;     // Variabel untuk metode Runge-Kutta

    // Menghitung kecepatan terminal secara teoritis menggunakan persamaan analitik
    vt_theoretical = sqrt((m * g) / c);
    printf("Kecepatan terminal (teoritis): %.3f m/s\n\n", vt_theoretical);

    // Header tabel output
    printf("Waktu (s)\tKecepatan (m/s)\n");
    printf("------------------------------\n");

    // Perulangan iterasi metode Runge-Kutta hingga waktu mencapai 20 detik
    while (t <= 20.0) {
        // Menampilkan waktu dan kecepatan saat ini
        printf("%.2f\t\t%.5f\n", t, v);

        // Implementasi metode Runge-Kutta orde 4
        // Langkah 1: hitung k1 pada titik awal
        k1 = dt * dvdt(v);

        // Langkah 2: hitung k2 pada titik tengah pertama
        k2 = dt * dvdt(v + 0.5 * k1);

        // Langkah 3: hitung k3 pada titik tengah kedua
        k3 = dt * dvdt(v + 0.5 * k2);

        // Langkah 4: hitung k4 pada titik akhir
        k4 = dt * dvdt(v + k3);

        // Gabungkan semua k untuk memperkirakan nilai v pada langkah berikutnya
        v = v + (1.0/6.0) * (k1 + 2*k2 + 2*k3 + k4);

        // Update waktu untuk langkah berikutnya
        t = t + dt;
    }

    return 0;
}
