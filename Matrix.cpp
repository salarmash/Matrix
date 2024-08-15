#include <iostream>

using namespace std;


class Matrix{
    friend ostream &operator <<(ostream &, const Matrix &);
    friend istream &operator >> (istream &, Matrix &);

private:
    int arr[3][3];

public:
    Matrix();
    Matrix (int (*)[3]);


    Matrix operator+(Matrix);
    Matrix operator-(Matrix);
    Matrix operator*(Matrix);
    bool operator==(Matrix);

};

Matrix::Matrix(){
    for(int i =0 ; i < 3 ; i++)
        for(int j =0; j<3; j++)
        arr[i][j] =0;

}
Matrix::Matrix(int (*ptr)[3]){
    for(int i =0 ; i < 3 ; i++)
        for(int j =0; j<3; j++)
        arr[i][j] =ptr[i][j];
}
Matrix Matrix::operator+(Matrix obj2){
    Matrix temp;
    for(int i =0 ; i < 3 ; i++)
        for(int j =0; j<3; j++)
        temp.arr[i][j] += arr[i][j] + obj2.arr[i][j];

    return temp;
}

Matrix Matrix::operator-(Matrix obj2){
    Matrix temp;
    for(int i =0 ; i < 3 ; i++)
        for(int j =0; j<3; j++)
        temp.arr[i][j] += arr[i][j] - obj2.arr[i][j];

    return temp;
}

Matrix Matrix::operator*(Matrix obj2){
    Matrix temp;
    for(int i =0 ; i < 3 ; i++)
        for(int j =0; j<3; j++)
            for(int k =0; k<3; k++)
        temp.arr[i][j] += arr[i][k] * obj2.arr[k][j];

    return temp;
}


bool Matrix::operator==(Matrix obj2){
    for(int i =0 ; i < 3 ; i++)
        for(int j =0; j<3; j++)

            if(arr[i][j] != obj2.arr[i][j])

            return false;
    return true;
}


ostream &operator <<(ostream &output, const Matrix &sample){

    for( int i=0 ; i < 3 ; i++ ){
                for( int j=0 ; j < 3 ; j++ ){
                    output << sample.arr[i][j] ;
                    if( j+1 < 3 )
                        output << " , " ;
                }

                output << endl ;
            }
            output<<"---------------------";
            return output ;



}

istream &operator >> (istream &input, Matrix &sample){
    for( int i=0 ; i < 3 ; i++ ){
                for( int j=0 ; j < 3 ; j++ ){
                    cout << " Enter value for index ["<< i <<"][" << j << "] = " ;
                    input >> sample.arr[i][j] ;
                }
            }
            return input ;
}





   int main(){

        Matrix a , b ;

        cin >> a >> b ;

        cout << " is Equal these Two Matrix : "
             << boolalpha << (a == b )<<endl;

        Matrix c = a + b ,
               d = a - b ,
               f = a * b ;

        cout <<"MATRIX A: " <<endl << a << endl
             << "MATRIX B: " << endl<< b << endl
             <<"SUM: "<<endl<< c << endl
             <<"SUBTRACTION: "<<endl<< d << endl
             <<"MULTIPLICATION"<<endl<< f << endl ;
        return 0;
    }



















