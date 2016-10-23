#define f(x) (x)  //举例函数
#define epsilon 0.0001  //精度
#define MAXREPT  10   //迭代次数,到最后仍达不到精度要求,则输出T(m=10).  
//亲测精度取0.001，迭代次数取15~16，精度取0.0001，迭代次数取15 by Yang
double Romberg(double aa, double bb)
{ //aa,bb 积分上下限
    int m, n;//m控制迭代次数, 而n控制复化梯形积分的分点数. n=2^m
    double h, x;
    double s, q;
    double ep; //精度要求
    double *y = new double[MAXREPT];//为节省空间,只需一维数组
    //每次循环依次存储Romberg计算表的每行元素,以供计算下一行,算完后更新
    double p;//p总是指示待计算元素的前一个元素(同一行)
    //迭代初值
    h = bb - aa;
    y[0] = h*(f(aa) + f(bb))/2.0;
    m = 1;
    n = 1;
    ep = epsilon + 1.0;
    //迭代计算
    while ((ep >= epsilon) && (m < MAXREPT))
    {
        //复化积分公式求T2n(Romberg计算表中的第一列),n初始为1,以后倍增
        p = 0.0;
        for (int i=0; i<n; i++)//求Hn
        {
            x = aa + (i+0.5)*h;
            p = p + f(x);
        }
        p = (y[0] + h*p)/2.0;//求T2n = 1/2(Tn+Hn),用p指示
        //求第m行元素,根据Romberg计算表本行的前一个元素(p指示),
        //和上一行左上角元素(y[k-1]指示)求得.      
        s = 1.0;
        for (int k=1; k<=m; k++)
        {
            s = 4.0*s;
            q = (s*p - y[k-1])/(s - 1.0);
            y[k-1] = p;
            p = q;
        }
        p = fabs(q - y[m-1]);
        m = m + 1;
        y[m-1] = q;
        n = n + n; h = h/2.0;
    }
    return (q);
}
