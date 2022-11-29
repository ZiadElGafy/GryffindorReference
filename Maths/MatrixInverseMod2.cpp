class Matrix
{
public:
    vector<vector<int>> mat;
    unsigned int rows, cols;
    Matrix(vector<vector<int>> mat)
    {
        this->mat = mat;
        rows = mat.size();
        cols = mat[0].size();
    }
 
    Matrix(int n, int m)
    {
        this->rows = n;
        this->cols = m;
        this->mat = vector<vector<int>>(n);
        for(int i = 0; i < n; i++)
            this->mat[i] = vector<int>(m);
    }
 
    Matrix operator * (Matrix &other)
    {
        vector<vector<int>> ret(rows, vector<int>(other.cols));
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < other.cols; j++)
            {
                int sum = 0;
                for(int k = 0; k < cols; k++)
                {
                    sum = (sum + 1ll * mat[i][k] * other.mat[k][j]) % mod;
                }
                ret[i][j] = sum;
            }
        }
        return Matrix(ret);
    }
 
    static Matrix identity_matrix(int n)
    {
        vector<vector<int>> ret(n, vector<int>(n));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    ret[i][j] = 1;
                else
                    ret[i][j] = 0;
            }
        }
        return Matrix(ret);
    }
 
    static Matrix fast_exponentiation(Matrix m, ll power)
    {
        Matrix ret = Matrix::identity_matrix(m.rows);
        while(power)
        {
            if(power & 1)
                ret = ret * m;
            m = m * m;
            power >>= 1;
        }
        return ret;
    }
 
    vector<vector<double>> inverse()
    {
        assert(rows == cols);
 
        int i = 0, j = 0, k = 0, n = 0;
        double d = 0.0;
 
        n = rows;
        vector<vector<double>> ret(2 * rows, vector<double>(2 * rows));
 
        //Inputs the coefficients of the matrix
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                ret[i][j] = mat[i][j];
            }
        }
 
        // Initializing Right-hand side to identity matrix
        for(i = 0; i < n; ++i)
        {
            ret[i][i + n] = 1;
        }
 
        // Partial pivoting
        for(i = n; i > 1; --i)
        {
            if(ret[i - 1][1] < ret[i][1])
            {
                for(j = 0; j < 2 * n; ++j)
                {
                    d = ret[i][j];
                    ret[i][j] = ret[i - 1][j];
                    ret[i - 1][j] = d;
                }
            }
        }
 
        // Reducing To Diagonal Matrix
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < 2 * n; ++j)
            {
                if(j != i)
                {
                    d = ret[j][i] / ret[i][i];
                    for(k = 0; k < 2 * n; ++k)
                    {
                        ret[j][k] -= ret[i][k] * d;
                    }
                }
            }
        }
 
        // Reducing To Unit Matrix
        for(i = 0; i < n; ++i)
        {
            d = ret[i][i];
            for(j = 0; j < 2 * n; ++j)
            {
                ret[i][j] = ret[i][j] / d;
            }
        }
 
        vector<vector<double>> tmp(rows, vector<double>(rows));
        for(int i=0; i < n; ++i)
            for(int j = n, j2 = 0; j < 2 * n; ++j, ++j2)
                tmp[i][j2] = ret[i][j];
 
        return tmp;
    }
};
