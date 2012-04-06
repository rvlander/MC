/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package org.mc.mcjavacore;

/**
 *
 * @author rvlander
 */
public class MCJLorAndTypeException extends Exception {

    public MCJLorAndTypeException() {
        System.err.println("Operands to the || and && operators must"+
                " be convertible to logical scalar values.");
    }
    
}
