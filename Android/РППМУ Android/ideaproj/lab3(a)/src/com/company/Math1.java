package com.company;

public class Math1 {
    public static double Pow_Dou(double a, double b){
        return Exp_Dou(b * Ln_Dou(a));
    }

    public static double Ln_Dou(double x){
        double a, b, eps, c=2;
        double y, y1;
        int n;
        eps = 0.0000001;
        a = (x - 1) / (x + 1);
        y = a;
        n = 1;
        b = a;
        while (Math.abs(a) > eps)
        {
            if (n == 1)
            {
                a = a * b * (x - 1) / ((x + 1) * (2 * n + 1));
            }
            else
            {
                a = a * b * (x - 1) * c / ((x + 1) * (2 * n + 1));
            }
            y = y + a;
            c = (2 * n + 1);
            n++;
        }
        y = y * 2;
        return y;
    }
    public static double Exp_Dou(double x){
        double a, n;
        double eps = 0.000000001;
        double y;
        a = 1;
        y = a;
        n = 1;
        while (Math.abs(a) > eps)
        {
            a = a * x / n;
            y = y + a;
            n++;
        }
        return y;
    }
    public static double Cos_Dou(double x){
        double a, eps;
        double y;
        int n;
        double g;
        eps = 0.00000001;
        a = 1;
        y = a;
        n = 1;
        g = x;
        while (g < 0)
        {
            g = g + 2 * Math.PI;
        }
        while (g > 2 * Math.PI)
        {
            g = g - 2 * Math.PI;
        }
        while (Math.abs(a) > eps)
        {
            a = a * (-1) * g * g / ((2 * n) * (2 * n - 1));
            y = y + a;
            n++;
        }
        return y;
    }
    public static double Sin_Dou(double x){
        double a, b, eps, c;
        double y, y1;
        int n;
        double g;
        eps = 0.00000001;
        g = x;
        while (g < 0)
        {
            g = g + 2 * Math.PI;
        }
        while (g > 2 * Math.PI)
        {
            g = g - 2 * Math.PI;
        }
        a = g;
        y = a;
        n = 1;
        while (Math.abs(a) > eps)
        {
            a = a * (-1) * g * g / (2 * n * (2 * n + 1));
            y = y + a;
            n++;
        }
        return y;
    }
    public static double Tan_Dou(double x){
        double a;
        a = Sin_Dou(x) / Cos_Dou(x);
        return a;
    }
    public static double Arctg_Dou(double x){
        double y=x;
        if (Math.abs(x) < 1)
        {
            double a, eps;
            int n;
            eps = 0.000001;
            a = x;
            y = a;
            n = 1;
            while (Math.abs(a) > eps)
            {
                a = a * (-1) * x * x  / (2 * n + 1);
                y = y + a;
                n++;
            }
        }
        else
        if (Math.abs(x) >= 1)
        {
            double a, b, eps ;
            int n;
            eps = 0.000001;
            a = -(1 / x);
            y = a;
            n = 1;
            while (Math.abs(a) > eps)
            {
                if (n == 1)
                {
                    a = a * (-1) / ((2 * n + 1) * x * x);
                }
                else if (n > 1)
                {
                    a = a * (-1)  / ((2 * n + 1) * x * x);
                }
                y = y + a;
                n++;
            }
            a = -(1 / x);
            if (a < 0)
            {
                y = Math.PI/2 + y;
            }
            else if (a > 0)
            {
                y = y - Math.PI/2;
            }
        }
        return y;
        /*double a = x;
        double sum = a;
        double b = a;
        double E = 0.000001;
        for(int i = 1; a > E; i++){
            b *= - x * x;
            a *= b / (2 * i + 1);
            sum += a;
        }
        return sum;*/
    }
    public static double Arcctg_Dou(double x){
        double a;
        a = Math.PI / 2 - Arctg_Dou(x);
        return a;
    }
    public static double Th_Dou(double x){
        double a;
        a = (Exp_Dou(x) - Exp_Dou(-1 * x)) / (Exp_Dou(x) + Exp_Dou(-1 * x));
        return a;
    }
    public static double Ch_Dou(double x) {
        double a, b, eps, c;
        double y, y1;
        int n;
        double g;
        eps = 0.000001;
        a = 1;
        y = a;
        n = 0;
        g = x;
        while (Math.abs(a) > eps)
        {
            if (n == 0)
            {
                a = a * g * g / 2;
            }
            else if (n >= 1)
            {
                a = a * g * g / ((2 * n + 2) * (2 * n + 1));
            }
            y = y + a;
            n++;
        }

        return y;
    }
    public static double Sh_Dou(double x) {
        double a, b, eps, c;
        double y, y1;
        int n;
        eps = 0.00000001;
        a = x;
        y = a;
        n = 1;
        while (Math.abs(a) > eps)
        {
            a = a * x * x / (2 * n * (2 * n + 1));
            y = y + a;
            n++;
        }
        return y;
    }
    public static double Arcsin_Dou(double x) {
        int n=0;
        double a=x, y=x, E=0.1e-5;
        while (Math.abs(a*=(x*x*(2*n+1)*(2*n+1)/(2*(n+1)*(2*n+3))))>E) {
            y+=a;
            n++;
        }
        return y;
    }

}
