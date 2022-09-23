#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
    Matrix(void) = default;

    Matrix operator*(const Matrix& mat) const;
    Matrix operator*(const double d);
    void set_identity(void);

public:
    double m[4][4] = {
        {1.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0, 0.0},
        {0.0, 0.0, 1.0, 0.0},
        {0.0, 0.0, 0.0, 1.0}
    };

};
#endif //MATRIX_H