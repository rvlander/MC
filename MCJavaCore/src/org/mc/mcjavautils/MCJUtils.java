/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.mc.mcjavautils;


import org.mc.mcjavacore.MCJElemPosition;
import static org.mc.mcjavacore.MCJBaseFunctions.*;

/**
 *
 * @author rvlander
 */
public class MCJUtils {
    
    public static void printMatrix(double[][] a,String name){
        System.out.println(name+" = ");
        for(int i=0;i<a.length;i++){
            String s= "   [";
            for(int j=0;j<a[0].length;j++){
                s += " "+a[i][j];
            }
            s+= " ]";
            System.out.println(s);
        }
    }
    
    public static void printMatrix(double[][] a){
        printMatrix(a,"");
    }
    public static boolean contains(double[][] a,double v){
        boolean res = false;
        for(int i=0;i<a.length;i++){
            for(int j=0;j<a[0].length;j++){
                res = res | a[i][j]==v;
            }
        }
        return res;
    }
    
    public static double[][] matrixFromBoolean(boolean b){
        if(b) return matrixFromDouble(1);
        else  return matrixFromDouble(0);
    }
    
    public static boolean isVector(double[][] m){
        double[][] s = size(m);
        return (s[0][0] == 1 || s[0][1] ==1)&& (s[0][0]*s[0][1] >=1);
    }
    
    public static double[] vectorToDoubleArray(double[][] m){
        if( m.length == 1 ) return m[0];
        else {
            double[] r = new double[m.length];
            for(int i=0;i<r.length;i++){
                r[i] = m[i][0];
            }
            return r;
        }
    }
    
        
    public static void copy(double[][] src,double[][] dest, int offi, int offj){
        for(int i=0; i<src.length && i+offi<dest.length; i++){
            for(int j=0;j<src[0].length && j+offj<dest[0].length;j++)
                dest[i+offi][j+offj] = src[i][j];
        }
    }
    
    public static void copy(double src,double[][] dest){
        for(int i=0;i<dest.length; i++){
            for(int j=0;j<dest[0].length;j++)
                dest[i][j] = src;
        }
    }
    
    public static double kthElemValue(double[][] a, int i){
        int j = i-1;
        int m = j/a.length;
        int k = j%a.length;
        return a[k][m];
    }
    
    public static MCJElemPosition kthElemPosition(double[][] a, int i){
        MCJElemPosition p = new MCJElemPosition();
        int j = i-1;
        //System.out.println(a[0].length);
        p.i = j%a.length;
        p.j= j/a.length;
        return p;
    }
    
    public static boolean isScalar(double[][] m){
        return numel(m)[0][0] == 1;
    }
    
    public static boolean all(double[][] m){
        if (numel(m)[0][0] == 0) return false;
        boolean res = true;
        for(int i=0;i<m.length;i++){
            for (int j=0;j<m[0].length;j++){
                res = m[i][j] !=0;
                if(!res) break;
            }
            if(!res) break;
        }
        return res;
    }
    
    public static boolean any(double[][] m){
        if (numel(m)[0][0] == 0) return false;
        boolean res = false;
        for(int i=0;i<m.length;i++){
            for (int j=0;j<m[0].length;j++){
                res = m[i][j] !=0;
                if(res) break;
            }
            if(res) break;
        }
        return res;
    }
    
    public static boolean sameSize(double[][] a, double[][] b){
        if(a.length == b.length) return a[0].length == b[0].length;
        else return false;
    }
    
    public static boolean isEqual(double[][] a, double[][] b){
        boolean res = true;
        
        if(!sameSize(a,b)){
            return false;
        }
        
        for(int i=0;i<a.length;i++){
            for(int j=0;j<a[0].length;j++){
                res = res && (a[i][j]==b[i][j]);
                if(!res) return res;
            }
        }
        
        return res;
    }
    
}
