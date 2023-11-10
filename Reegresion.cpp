#include <iostream>
#include <vector>

using namespace std;

class RegresionLineal {
private:
    vector<float> x_data;
    vector<float> y_data;
    float b1;
    float b0;

public:
    RegresionLineal(vector<float> x, vector<float> y)
        : x_data(x), y_data(y), b1(0), b0(0) {}

        void calcularRegresion() {
            int n = x_data.size();
            float sum_x = 0;
            float sum_y = 0;
            float sum_xy = 0;
            float sum_x2 = 0;

                for (int i = 0; i < n; i++) {
                sum_x += x_data[i];
                sum_y += y_data[i];
                sum_xy += x_data[i] * y_data[i];
                sum_x2 += x_data[i] * x_data[i];
                }   

                    b1 = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
                    b0 = (sum_y - b1 * sum_x) / n;
        }

    float predecir(float x) {
        return b1 * x + b0;
    }

    void imprimirCoeficientes() {
        cout << "B1: " << b1 << endl;
        cout << "B0: " << b0 << endl;
    
    }
};

int main() {
    vector<float> x = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<float> y = {2, 4, 6, 8, 10, 12, 14, 16, 18};

    RegresionLineal regresion(x, y);
    regresion.calcularRegresion();

    cout << "Resultados de la regresión lineal:" << endl;
    regresion.imprimirCoeficientes();


    vector<float> valores_publicidad = {10, 11, 12, 13, 14};
    cout << "Predicciones de ventas para diferentes valores de publicidad:" << endl;
    for (float valor : valores_publicidad) {
        float prediccion = regresion.predecir(valor);
        cout << "Publicidad: " << valor <<  ", Predicción de ventas: " << prediccion << endl;
    }

    return 0;

}