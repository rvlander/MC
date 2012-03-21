/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.mc.mcjavacore;

import java.util.Arrays;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
import static org.mc.mcjavautils.MCJUtils.*;

/**
 *
 * @author rvlander
 */

/*
  => ADD
  => MINUS 
  * | expr '*' expr
 * {$$.source = "mtimes("+$1.source+","+$3.source+")";} 
 * | expr TIMES expr {$$.source = "times("+$1.source+","+$3.source+")";} | expr '/' expr
 * {$$.source = "mdivide("+$1.source+","+$3.source+")";} | expr DIVIDE expr
 * {$$.source = "divide("+$1.source+","+$3.source+")";} | expr '^' expr
 * {$$.source = "mpow("+$1.source+","+$3.source+")";} | expr POWER expr
 * {$$.source = "pow("+$1.source+","+$3.source+")";} | '(' expr ')' {$$.source =
 * "("+$2.source+")";} | '-' expr %prec MOINSUNAIRE { $$.source =
  => UMINUS 
  * | colon_expr {$$.source =
 * "colon("+$1.start+",1,"+$1.stop+")";} | colon_expr1 {$$.source =
 * "colon("+$1.start+","+$1.stride+","+$1.stop+")";} | NBRE { $$.source =
 * $1.source;} | ID { $$.source = $1.source;} ;
 */
public class MCJOperators {

//operateurs normaux
    private static double[][] add(double[][] t, double a) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] += a;
            }
        }
        return res;
    }

    public static double[][] add(double[][] t1, double[][] t2) throws MCJCMatrixDimensionsExceptions {
        double[][] res;
        if (numel(t1)[0][0] == 1) {
            res = add(t2, t1[0][0]);
        } else if (numel(t2)[0][0] == 1) {
            res = add(t1, t2[0][0]);
        } else if(Arrays.equals(size(t1)[0], size(t2)[0]))  {
        res = new double[t1.length][t1[0].length];
            for (int i = 0; i < t1.length; i++) {
                for (int j = 0; j < t1[0].length; j++) {
                    res[i][j] = t1[i][j] + t2[i][j];
                }
            }
        } else {
            throw new MCJCMatrixDimensionsExceptions();
        }

        return res;
    }
    
    public static double[][] uminus(double[][] t) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = - t[i][j];
            }
        }
        return res;
    }
    
    public static double[][] minus (double[][] t1, double[][] t2) throws MCJCMatrixDimensionsExceptions{
        return add(t1,uminus(t2));
    }
    
    
// operateurs de comparaison
    private static double[][] eq(double[][] t, double a) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = (a == res[i][j] ? 1 : 0);
            }
        }
        return res;
    }

    public static double[][] eq(double[][] t1, double[][] t2) throws MCJCMatrixDimensionsExceptions {
        double[][] res;
        if (numel(t1)[0][0] == 1) {
            res = eq(t2, t1[0][0]);
        } else if (numel(t2)[0][0] == 1) {
            res = eq(t1, t2[0][0]);
        } else if (Arrays.equals(size(t1)[0], size(t2)[0])) {
            res = new double[t1.length][t1[0].length];
            for (int i = 0; i < t1.length; i++) {
                for (int j = 0; j < t1[0].length; j++) {
                    res[i][j] = (t1[i][j] == t2[i][j] ? 1 : 0);
                }
            }
        } else {
            throw new MCJCMatrixDimensionsExceptions();
        }

        return res;
    }
    
    public static double[][] colon(double[][] start, double[][] stride, double[][] stop){
        double[][] res;
        if(contains(size(start),0)|contains(size(stride),0)|contains(size(stop),0)){
            res = new double[1][0];
        }else{
            double deb = start[0][0]; double step = stride[0][0]; double fin = stop[0][0];
            int n = ((fin%step>0)?1:0) +(int)Math.floor(fin/step);
            res = new double[1][n];
            res[0][0] = deb;
            for(int i=1;i<res[0].length;i++){
                res[0][i] = res[0][i-1] + step;
            }
        }
        return res;
    }
    
    public static void main(String args[]){
        printMatrix(colon(matrixFromDouble(1),matrixFromDouble(3.6),matrixFromDouble(10)));
    }
    
}
