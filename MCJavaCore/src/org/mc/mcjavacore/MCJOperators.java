/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.mc.mcjavacore;

import java.util.Arrays;
import java.util.logging.Level;
import java.util.logging.Logger;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
import static org.mc.mcjavautils.MCJUtils.*;

/**
 *
 * @author rvlander
 */

/*
 * => ADD => MINUS => MTIMES => TIMES "/" {$$.source =
 * "mdivide("+$1.source+","+$3.source+")";} | expr DIVIDE expr * {$$.source =
 * "divide("+$1.source+","+$3.source+")";} | expr '^' expr {$$.source =
 * "mpow("+$1.source+","+$3.source+")";} | expr POWER expr {$$.source = =>POW =>
 * UMINUS => COlon
 */
public class MCJOperators {

//operateurs normaux
    private static double[][] add(double[][] t, double a) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = t[i][j] + a;
            }
        }
        return res;
    }

    public static double[][] add(double[][] t1, double[][] t2) throws MCJCMatrixDimensionsException {
        double[][] res;
        if (numel(t1)[0][0] == 1) {
            res = add(t2, t1[0][0]);
        } else if (numel(t2)[0][0] == 1) {
            res = add(t1, t2[0][0]);
        } else if (Arrays.equals(size(t1)[0], size(t2)[0])) {
            res = new double[t1.length][t1[0].length];
            for (int i = 0; i < t1.length; i++) {
                for (int j = 0; j < t1[0].length; j++) {
                    res[i][j] = t1[i][j] + t2[i][j];
                }
            }
        } else {
            throw new MCJCMatrixDimensionsException();
        }

        return res;
    }

    private static double[][] times(double[][] t, double a) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = t[i][j] * a;
            }
        }
        return res;
    }

    public static double[][] mtimes(double[][] t1, double[][] t2) throws MCJCMatrixDimensionsException {
        double[][] res;
        if (numel(t1)[0][0] == 1) {
            res = times(t2, t1[0][0]);
        } else if (numel(t2)[0][0] == 1) {
            res = times(t1, t2[0][0]);
        } else if (size(t1)[0][1] == size(t2)[0][0]) {
            res = new double[t1.length][t2[0].length];
            for (int i = 0; i < t1.length; i++) {
                for (int j = 0; j < t2[0].length; j++) {
                    for (int k = 0; k < t2.length; k++) {
                        res[i][j] += t1[i][k] + t2[k][j];
                    }
                }
            }
        } else {
            throw new MCJCMatrixDimensionsException();
        }

        return res;
    }

    public static double[][] times(double[][] t1, double[][] t2) throws MCJCMatrixDimensionsException {
        double[][] res;
        if (numel(t1)[0][0] == 1) {
            res = times(t2, t1[0][0]);
        } else if (numel(t2)[0][0] == 1) {
            res = times(t1, t2[0][0]);
        } else if (Arrays.equals(size(t1)[0], size(t2)[0])) {
            res = new double[t1.length][t1[0].length];
            for (int i = 0; i < t1.length; i++) {
                for (int j = 0; j < t1[0].length; j++) {
                    res[i][j] = t1[i][j] * t2[i][j];
                }
            }
        } else {
            throw new MCJCMatrixDimensionsException();
        }

        return res;
    }

    public static double[][] uminus(double[][] t) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = -t[i][j];
            }
        }
        return res;
    }

    public static double[][] minus(double[][] t1, double[][] t2) throws MCJCMatrixDimensionsException {
        return add(t1, uminus(t2));
    }

    private static double[][] power(double[][] t, double a) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = Math.pow(t[i][j], a);
            }
        }
        return res;
    }

    private static double[][] power(double a, double[][] t) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = Math.pow(a, t[i][j]);
            }
        }
        return res;
    }

    public static double[][] power(double[][] t1, double[][] t2) throws MCJCMatrixDimensionsException {
        double[][] res;
        if (numel(t1)[0][0] == 1) {
            res = power(t1[0][0], t2);
        } else if (numel(t2)[0][0] == 1) {
            res = power(t1, t2[0][0]);
        } else if (Arrays.equals(size(t1)[0], size(t2)[0])) {
            res = new double[t1.length][t1[0].length];
            for (int i = 0; i < t1.length; i++) {
                for (int j = 0; j < t1[0].length; j++) {
                    res[i][j] = Math.pow(t1[i][j], t2[i][j]);
                }
            }
        } else {
            throw new MCJCMatrixDimensionsException();
        }

        return res;
    }

// operateurs de comparaison
    private static double[][] eq(double[][] t, double a) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = (a == t[i][j] ? 1 : 0);
            }
        }
        return res;
    }

    public static double[][] eq(double[][] t1, double[][] t2) throws MCJCMatrixDimensionsException {
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
            throw new MCJCMatrixDimensionsException();
        }

        return res;
    }

    public static double[][] colon(double[][] start, double[][] stride, double[][] stop) {
        double[][] res;
        if (contains(size(start), 0) | contains(size(stride), 0) | contains(size(stop), 0) | stop[0][0] < start[0][0]) {
            res = new double[1][0];
        } else {
            double deb = start[0][0];
            double step = stride[0][0];
            double fin = stop[0][0];
            double delta = fin - deb;
            int n = (int) (1 + Math.floor(delta / step));
            res = new double[1][n];
            res[0][0] = deb;
            for (int i = 1; i < res[0].length; i++) {
                res[0][i] = res[0][i - 1] + step;
            }
        }
        return res;
    }

    public static double[][] colon(double[][] start, double[][] stop) {
        return colon(start, matrixFromDouble(1), stop);
    }

    public static double[][] vertcat(double[][] top, double[][] bottom) throws MCJCMatrixDimensionsException {
        double[][] res;
        if (numel(top)[0][0] == 0) {
            res = duplicate(bottom);
        } else if (numel(bottom)[0][0] == 0) {
            res = duplicate(top);
        } else if (top[0].length == bottom[0].length) {
            res = new double[top.length + bottom.length][top[0].length];
            copy(top, res, 0, 0);
            copy(bottom, res, top.length, 0);
        } else {
            throw new MCJCMatrixDimensionsException();
        }
        return res;
    }

    public static double[][] horzcat(double[][] left, double[][] right) throws MCJCMatrixDimensionsException {
        double[][] res;
        if (numel(left)[0][0] == 0) {
            res = duplicate(right);
        } else if (numel(right)[0][0] == 0) {
            res = duplicate(left);
        } else if (left.length == right.length) {
            res = new double[left.length][left[0].length + right[0].length];
            copy(left, res, 0, 0);
            copy(right, res, 0, left[0].length);
        } else {
            throw new MCJCMatrixDimensionsException();
        }
        return res;
    }

    public static double[][] subsref(double[][] A, double[][][] indexes) throws MCJCIndexExceedsMatrixDimensions {
        if (indexes == null) {
            return duplicate(A);
        }
        if (indexes.length == 1) {
            if (indexes[0] == null) {
                return duplicate(A);
            } else {
                double[][] m = indexes[0];
                double[][] s = size(m);
                double[][] res = new double[(int) s[0][0]][(int) s[0][1]];
                if (numel(m)[0][0] >= 1) {
                    for (int i = 0; i < m.length; i++) {
                        for (int j = 0; j < m[0].length; j++) {
                            if(i>=A.length || (int)indexes[0][i][j] > A[0].length)
                                throw new MCJCIndexExceedsMatrixDimensions();
                            res[i][j] = A[i][(int)( indexes[0][i][j])-1];
                        }
                    }
                }
                return res;
            }
        }
        if(indexes.length ==2 ){
            if(indexes[0] == null) indexes[0] = colon(matrixFromDouble(1),matrixFromDouble(1),matrixFromDouble(A.length));
            if(indexes[1] == null) indexes[1] = colon(matrixFromDouble(1),matrixFromDouble(1),matrixFromDouble(A[0].length));    
            //a corriger ?    
            if(numel(indexes[0])[0][0] == 0 || numel(indexes[1])[0][0] == 0){
                return new double[0][(int)numel(indexes[1])[0][0]];
            }
            if(!isVector(indexes[0])||!isVector(indexes[1])){
                throw new MCJCIndexExceedsMatrixDimensions();
            }
            double[] iIndex = vectorToDoubleArray(indexes[0]);
            double[] jIndex = vectorToDoubleArray(indexes[1]);
            
            double[][] res = new double[iIndex.length][jIndex.length];
            
            for(int i=0; i < iIndex.length; i++){
                for(int j=0; j<jIndex.length; j++){
                    if((int)iIndex[i] > A.length || (int)jIndex[j] > A[0].length ){
                        throw new MCJCIndexExceedsMatrixDimensions();
                    }
                    res[i][j] = A[(int)iIndex[i]-1][(int)jIndex[j]-1];
                }
            }
            return res;
            
        }
        if(indexes.length >2){
            throw new MCJCIndexExceedsMatrixDimensions();
        }
        //normally not here
        System.err.println("subsref : pas là");
        return new double[0][0];
    }

    public static void main(String args[]) {
        try {
            double[][] A = vertcat(horzcat(matrixFromDouble(7), matrixFromDouble(5)), horzcat(matrixFromDouble(7), matrixFromDouble(6)));
            double[][] B = matrixFromDouble(3);
            double[][] C = mtimes(A, B);
            A = matrixFromDouble(7);
            printMatrix(A);
            printMatrix(B);
            printMatrix(C);

        } catch (MCJCMatrixDimensionsException ex) {
            Logger.getLogger(MCJOperators.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
