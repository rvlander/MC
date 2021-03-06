/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.mc.mcjavacore;

import Jama.Matrix;
import java.util.Arrays;
import java.util.logging.Level;
import java.util.logging.Logger;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
import org.mc.mcjavautils.MCJUtils;
import static org.mc.mcjavautils.MCJUtils.*;

/**
 *
 * @author rvlander
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

    public static double[][] add(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        double[][] res;
        /*printMatrix(size(t1));
        printMatrix(size(t2));*/
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
            throw new MCJMatrixDimensionsException();
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

    public static double[][] mtimes(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
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
                        res[i][j] += t1[i][k] * t2[k][j];
                    }
                }
            }
        } else {
            printMatrix(size(t1));
            printMatrix(size(t2));
            throw new MCJMatrixDimensionsException();
        }

        return res;
    }

    private static double[][] rdivide(double a, double[][] t) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = a / t[i][j];
            }
        }
        return res;
    }

    private static double[][] rdivide(double[][] t, double a) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = t[i][j] / a;
            }
        }
        return res;
    }

    public static double[][] rdivide(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        double[][] res;
        if (numel(t1)[0][0] == 1) {
            res = rdivide(t1[0][0], t2);
        } else if (numel(t2)[0][0] == 1) {
            res = rdivide(t1, t2[0][0]);
        } else if (Arrays.equals(size(t1)[0], size(t2)[0])) {
            res = new double[t1.length][t1[0].length];
            for (int i = 0; i < t1.length; i++) {
                for (int j = 0; j < t1[0].length; j++) {
                    res[i][j] = t1[i][j] / t2[i][j];
                }
            }
        } else {
            printMatrix(size(t1),"t1");
            printMatrix(size(t1),"t2");
            throw new MCJMatrixDimensionsException();
        }

        return res;
    }

    private static double[][] mod(double a, double[][] t) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = a % t[i][j];
            }
        }
        return res;
    }

    private static double[][] mod(double[][] t, double a) {
        //printMatrix(size(t),"t");
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = t[i][j] % a;
            }
        }
        return res;
    }

    public static double[][] mod(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        double[][] res;
        if (numel(t1)[0][0] == 1) {
            res = mod(t1[0][0], t2);
        } else if (numel(t2)[0][0] == 1) {
            res = mod(t1, t2[0][0]);
        } else if (Arrays.equals(size(t1)[0], size(t2)[0])) {
            res = new double[t1.length][t1[0].length];
            for (int i = 0; i < t1.length; i++) {
                for (int j = 0; j < t1[0].length; j++) {
                    res[i][j] = t1[i][j] % t2[i][j];
                }
            }
        } else {
            throw new MCJMatrixDimensionsException();
        }

        return res;
    }
    public static double[][] rem(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        return mod(add(mod(t1,t2),t2),t2);
    }

    public static double[][] ldivide(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        return rdivide(t2, t1);
    }

    private static double[][] mldivide(double a, double[][] t) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = t[i][j]/a;
            }
        }
        return res;
    }

    private static double[][] mldivide(double[][] t, double a) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = a/t[i][j];
            }
        }
        return res;
    }

    public static double[][] mldivide(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        double[][] res;
        if (numel(t1)[0][0] == 1) {
            res = mrdivide(t1[0][0], t2);
        } else if (numel(t2)[0][0] == 1) {
            res = mrdivide(t1, t2[0][0]);
        } else {
            
            Matrix A = new Matrix(t1,t1.length,t1[0].length);
            Matrix B = new Matrix(t2,t2.length,t2[0].length);
            
           // printMatrix(size(t1));
           // System.out.println(A.rank());
            
            Matrix C = A.inverse().times(B);
            res = C.getArray();
            
//            throw new MCJMatrixDimensionsException();
        }

        return res;
    }

    private static double[][] mrdivide(double a, double[][] t) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = a / t[i][j];
            }
        }
        return res;
    }

    private static double[][] mrdivide(double[][] t, double a) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = t[i][j] / a;
            }
        }
        return res;
    }

    public static double[][] mrdivide(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        double[][] res;
        if (numel(t1)[0][0] == 1) {
            res = mrdivide(t1[0][0], t2);
        } else if (numel(t2)[0][0] == 1) {
            res = mrdivide(t1, t2[0][0]);
        } else {
            Matrix A = new Matrix(t1,t1.length,t1[0].length);
            Matrix B = new Matrix(t2,t2.length,t2[0].length);
            
            Matrix C = A.times(B.inverse());
            res = C.getArray();
        }

        return res;
    }
    

    public static double[][] times(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        double[][] res;
        /*printMatrix(size(t1));
        printMatrix(size(t2));*/
        
        if(numel(t1)[0][0]==0 || numel(t2)[0][0]==0){
            return new double[0][0];
        }
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
        }else {
            printMatrix(size(t1));
            printMatrix(size(t2));
            throw new MCJMatrixDimensionsException();
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

    public static double[][] minus(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
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

    public static double[][] power(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
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
            throw new MCJMatrixDimensionsException();
        }

        return res;
    }

    public static double[][] mpower(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    public static double[][] colon(double[][] start, double[][] stride, double[][] stop) {
        double[][] res;
        if (contains(size(start), 0) | contains(size(stride), 0) | contains(size(stop), 0)) {
            res = new double[1][0];
        } else {
            double deb = start[0][0];
            double step = stride[0][0];
            double fin = stop[0][0];
            double delta = fin - deb;
            int n = (int) (1 + Math.floor(delta / step));
            if (n <= 0) {
                return new double[1][0];
            }
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

    public static double[][] vertcat(double[][] top, double[][] bottom) throws MCJMatrixDimensionsException {
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
            throw new MCJMatrixDimensionsException();
        }
        return res;
    }

    public static double[][] horzcat(double[][] left, double[][] right) throws MCJMatrixDimensionsException {
        double[][] res;
        //printMatrix(size(left));
        //printMatrix(size(right));
        if (numel(left)[0][0] == 0) {
            res = duplicate(right);
        } else if (numel(right)[0][0] == 0) {
            res = duplicate(left);
        } else if (left.length == right.length) {
            res = new double[left.length][left[0].length + right[0].length];
            copy(left, res, 0, 0);
            copy(right, res, 0, left[0].length);
        } else {
            throw new MCJMatrixDimensionsException();
        }
        return res;
    }

    public static double[][] subsref(double[][] A, double[][][] indexes) throws MCJIndexExceedsMatrixDimensions {

        // printMatrix(size(A));

        if (indexes == null) {
            return duplicate(A);
        }
        if (indexes.length == 1) {
            double[][] m;
            if (indexes[0] == null) {
                m = colon(matrixFromDouble(1), matrixFromDouble(1), numel(A));
                m = transpose(m);
            } else {
                m = indexes[0];
            }
            double[][] res = new double[m.length][m[0].length];
            int n = (int) numel(m)[0][0];
            for (int i = 1; i <= n; i++) {
                MCJElemPosition p = kthElemPosition(A, (int) kthElemValue(m, i));
                MCJElemPosition q = kthElemPosition(m, i);
                res[q.i][q.j] = A[p.i][p.j];

            }

            if(isVector(A) && A.length>1){
                res =transpose(res);
            }
            
            return res;
        }
        /*if (indexes.length == 1) {
            if (indexes[0] == null) {
                return duplicate(A);
            } else {
                double[][] m = indexes[0];
                double[][] s = size(m);
                double[][] res = new double[(int) s[0][0]][(int) s[0][1]];
                if (numel(m)[0][0] >= 1) {
                    for (int i = 0; i < m.length; i++) {
                        for (int j = 0; j < m[0].length; j++) {
                            if (i >= A.length || (int) indexes[0][i][j] > A[0].length) {
                                throw new MCJIndexExceedsMatrixDimensions();
                            }
                            res[i][j] = A[i][(int) (indexes[0][i][j]) - 1];
                        }
                    }
                }
                return res;
            }
        }*/
        if (indexes.length == 2) {
            if (indexes[0] == null) {
                indexes[0] = colon(matrixFromDouble(1), matrixFromDouble(1), matrixFromDouble(A.length));
            }
            if (indexes[1] == null) {
                indexes[1] = colon(matrixFromDouble(1), matrixFromDouble(1), matrixFromDouble(A[0].length));
            }
            //a corriger ?    
            if (numel(indexes[0])[0][0] == 0 || numel(indexes[1])[0][0] == 0) {
                return new double[0][(int) numel(indexes[1])[0][0]];
            }
            if (!isVector(indexes[0]) || !isVector(indexes[1])) {
                throw new MCJIndexExceedsMatrixDimensions();
            }
            double[] iIndex = vectorToDoubleArray(indexes[0]);
            double[] jIndex = vectorToDoubleArray(indexes[1]);

            double[][] res = new double[iIndex.length][jIndex.length];

            for (int i = 0; i < iIndex.length; i++) {
                for (int j = 0; j < jIndex.length; j++) {
                    if ((int) iIndex[i] > A.length || (int) jIndex[j] > A[0].length) {
                        System.out.println(iIndex[i] +" "+ A.length);
                        System.out.println(jIndex[j] +" "+ A[0].length);
                        throw new MCJIndexExceedsMatrixDimensions();
                    }
                    res[i][j] = A[(int) iIndex[i] - 1][(int) jIndex[j] - 1];
                }
            }
            return res;

        }
        if (indexes.length > 2) {
            throw new MCJIndexExceedsMatrixDimensions();
        }
        //normally not here
        System.err.println("subsref : pas là");
        return new double[0][0];
    }
    
     public static double[][] cell_subsref(double[][][] A, double[][] index) throws MCJIndexExceedsMatrixDimensions {
        return A[(int)index[0][0]];
    }
    
    public static double[][] assign(double[][] A,double val ,int i,int j){
        double[][] s = size(A);
        double[][] res;
        res = new double[(int)Math.max(i+1, s[0][0])][(int)Math.max(j+1, s[0][1])];
        copy(A,res,0,0);
        //printMatrix(size(res));
        res[i][j] = val;
        return res;
    }

    public static double[][] subsasgn(double[][] A, double[][][] indexes, double[][] B) throws MCJMatrixDimensionsException, MCJIndexExceedsMatrixDimensions {

        if (indexes == null) {
            throw new MCJMatrixDimensionsException();
        }
        if (indexes.length == 1) {
            double[][] m;
            if (indexes[0] == null) {
                m = colon(matrixFromDouble(1), matrixFromDouble(1), numel(A));
            } else {
                m = indexes[0];
            }
            if (!isScalar(B) && (numel(m)[0][0] != numel(B)[0][0])) {
                throw new MCJMatrixDimensionsException();
            }
            int n = (int) numel(m)[0][0];
            for (int i = 1; i <= n; i++) {
                MCJElemPosition p = kthElemPosition(A, (int) kthElemValue(m, i));
                if (isScalar(B)) {
                    A = assign(A,B[0][0],p.i,p.j);
                } else {
                    MCJElemPosition q = kthElemPosition(B, i);
                    A = assign(A,B[q.i][q.j],p.i,p.j);
                }
            }

            return A;
        }
        if (indexes.length == 2) {
            if (indexes[0] == null) {
                indexes[0] = colon(matrixFromDouble(1), matrixFromDouble(1), matrixFromDouble(A.length));
            }
            if (indexes[1] == null) {
                indexes[1] = colon(matrixFromDouble(1), matrixFromDouble(1), matrixFromDouble(A[0].length));
            }
            //a corriger ?    
            if (numel(indexes[0])[0][0] == 0 || numel(indexes[1])[0][0] == 0) {
                return new double[0][0];
            }
            if (!isVector(indexes[0]) || !isVector(indexes[1])) {
                throw new MCJIndexExceedsMatrixDimensions();
            }
            double[] iIndex = vectorToDoubleArray(indexes[0]);
            double[] jIndex = vectorToDoubleArray(indexes[1]);

           /* MCJUtils.printMatrix(indexes[0]);
            MCJUtils.printMatrix(indexes[1]);*/

            if (!isScalar(B) && (iIndex.length != B.length || jIndex.length != B[0].length)) {
                throw new MCJIndexExceedsMatrixDimensions();
            }

            for (int i = 0; i < iIndex.length; i++) {
                for (int j = 0; j < jIndex.length; j++) {
                    if (isScalar(B)) {
                        A = assign(A,B[0][0],(int) iIndex[i] - 1,(int) jIndex[j] - 1);
                    } else {
                        A = assign(A,B[i][j],(int) iIndex[i] - 1,(int) jIndex[j] - 1);
                    }
                }
            }
            return A;
        }
        if (indexes.length > 2) {
            throw new MCJIndexExceedsMatrixDimensions();
        }
        //normally not here
        System.err.println("subsref : pas là");
        return new double[0][0];
    }

    public static double[][] transpose(double[][] a) {
        if (numel(a)[0][0] == 0) {
            return new double[0][0];
        } else {
            double[][] res = new double[a[0].length][a.length];
            for (int i = 0; i < a.length; i++) {
                for (int j = 0; j < a[0].length; j++) {
                    res[j][i] = a[i][j];
                }
            }
            return res;
        }

    }

    public static double[][] ctranspose(double[][] a) {
        return transpose(a);
    }

    public static double[][] not(double[][] a) {
        if (numel(a)[0][0] == 0) {
            return new double[0][0];
        } else {
            double[][] res = new double[a.length][a[0].length];
            for (int i = 0; i < a.length; i++) {
                for (int j = 0; j < a[0].length; j++) {
                    if (a[i][j] != 0) {
                        res[i][j] = 0;
                    } else {
                        res[i][j] = 1;
                    }
                }
            }
            return res;
        }
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

    public static double[][] eq(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
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
            throw new MCJMatrixDimensionsException();
        }

        return res;
    }

    public static double[][] ne(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        return not(eq(t1, t2));
    }

    private static double[][] lt(double a, double[][] t) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = (a < t[i][j] ? 1 : 0);
            }
        }
        return res;
    }

    private static double[][] lt(double[][] t, double a) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = (t[i][j] < a ? 1 : 0);
            }
        }
        return res;
    }

    public static double[][] lt(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        double[][] res;
        if (numel(t1)[0][0] == 1) {
            res = lt(t1[0][0], t2);
        } else if (numel(t2)[0][0] == 1) {
            res = lt(t1, t2[0][0]);
        } else if (Arrays.equals(size(t1)[0], size(t2)[0])) {
            res = new double[t1.length][t1[0].length];
            for (int i = 0; i < t1.length; i++) {
                for (int j = 0; j < t1[0].length; j++) {
                    res[i][j] = (t1[i][j] < t2[i][j] ? 1 : 0);
                }
            }
        } else {
            throw new MCJMatrixDimensionsException();
        }

        return res;
    }

    private static double[][] gt(double a, double[][] t) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = (a > t[i][j] ? 1 : 0);
            }
        }
        return res;
    }

    private static double[][] gt(double[][] t, double a) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = (t[i][j] > a ? 1 : 0);
            }
        }
        return res;
    }

    public static double[][] gt(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        double[][] res;
        if (numel(t1)[0][0] == 1) {
            res = gt(t1[0][0], t2);
        } else if (numel(t2)[0][0] == 1) {
            res = gt(t1, t2[0][0]);
        } else if (Arrays.equals(size(t1)[0], size(t2)[0])) {
            res = new double[t1.length][t1[0].length];
            for (int i = 0; i < t1.length; i++) {
                for (int j = 0; j < t1[0].length; j++) {
                    res[i][j] = (t1[i][j] > t2[i][j] ? 1 : 0);
                }
            }
        } else {
            throw new MCJMatrixDimensionsException();
        }

        return res;
    }

    public static double[][] le(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        return not(gt(t1, t2));
    }

    public static double[][] ge(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        return not(lt(t1, t2));
    }

    private static double[][] and(double[][] t, double a) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = (a * t[i][j] == 0 ? 0 : 1);
            }
        }
        return res;
    }

    public static double[][] and(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        double[][] res;
        if (numel(t1)[0][0] == 1) {
            res = and(t2, t1[0][0]);
        } else if (numel(t2)[0][0] == 1) {
            res = and(t1, t2[0][0]);
        } else if (Arrays.equals(size(t1)[0], size(t2)[0])) {
            res = new double[t1.length][t1[0].length];
            for (int i = 0; i < t1.length; i++) {
                for (int j = 0; j < t1[0].length; j++) {
                    res[i][j] = (t1[i][j] * t2[i][j] == 0 ? 0 : 1);
                }
            }
        } else {
            throw new MCJMatrixDimensionsException();
        }

        return res;
    }

    private static double[][] or(double[][] t, double a) {
        double[][] res = new double[t.length][t[0].length];  // /!\
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                res[i][j] = (a == 0 && t[i][j] == 0 ? 0 : 1);
            }
        }
        return res;
    }

    public static double[][] or(double[][] t1, double[][] t2) throws MCJMatrixDimensionsException {
        double[][] res;
        if (numel(t1)[0][0] == 1) {
            res = or(t2, t1[0][0]);
        } else if (numel(t2)[0][0] == 1) {
            res = or(t1, t2[0][0]);
        } else if (Arrays.equals(size(t1)[0], size(t2)[0])) {
            res = new double[t1.length][t1[0].length];
            for (int i = 0; i < t1.length; i++) {
                for (int j = 0; j < t1[0].length; j++) {
                    res[i][j] = (t1[i][j] == 0 && t2[i][j] == 0 ? 0 : 1);
                }
            }
        } else {
            throw new MCJMatrixDimensionsException();
        }

        return res;
    }

    public static double[][] land(double[][] t1, double[][] t2) throws MCJLorAndTypeException {
        if (!isScalar(t1) | !isScalar(t2)) {
            throw new MCJLorAndTypeException();
        }
        return matrixFromDouble(t1[0][0] * t2[0][0] == 0 ? 0 : 1);
    }

    public static double[][] lor(double[][] t1, double[][] t2) throws MCJLorAndTypeException {
        if (!isScalar(t1) | !isScalar(t2)) {
            throw new MCJLorAndTypeException();
        }
        return matrixFromDouble(t1[0][0] == 0 && t2[0][0] == 0 ? 0 : 1);
    }
}
