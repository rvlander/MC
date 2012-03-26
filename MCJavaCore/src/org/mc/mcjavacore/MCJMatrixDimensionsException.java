/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.mc.mcjavacore;

/**
 *
 * @author rvlander
 */
public class MCJMatrixDimensionsException extends Exception {

    public MCJMatrixDimensionsException() {
        System.err.println("Matrix dimensions must agree");
    }
    
}
