/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.mc.mcjavacore;

/**
 *
 * @author rvlander
 */
public class MCJIndexExceedsMatrixDimensions extends Exception {

    public MCJIndexExceedsMatrixDimensions() {
        System.err.println("Index exceeds matrix dimensions");
    }
    
}
