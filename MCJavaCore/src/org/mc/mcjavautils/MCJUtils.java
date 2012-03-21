/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.mc.mcjavautils;

/**
 *
 * @author rvlander
 */
public class MCJUtils {
    
    public static void printMatrix(double[][] a){
        for(int i=0;i<a.length;i++){
            String s= "[";
            for(int j=0;j<a[0].length;j++){
                s += " "+a[i][j];
            }
            s+= " ]";
            System.out.println(s);
        }
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
    
}
