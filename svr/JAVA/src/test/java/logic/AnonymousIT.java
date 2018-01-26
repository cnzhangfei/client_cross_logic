/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package logic;

import org.junit.After;
import org.junit.AfterClass;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.fail;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

/**
 *
 * @author ShiHua
 */
public class AnonymousIT {

    public AnonymousIT() {
    }

    @BeforeClass
    public static void setUpClass() {
    }

    @AfterClass
    public static void tearDownClass() {
    }

    @Before
    public void setUp() {
    }

    @After
    public void tearDown() {
    }

    /**
     * Test of Init method, of class Anonymous.
     */
    @Test
    public void testInit_InitRequest() {
        System.out.println("Init");
        InitRequest req = null;
        Anonymous instance = new Anonymous();
        InitResponse expResult = null;
        InitResponse result = instance.Init(req);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of Init method, of class Anonymous.
     */
    @Test
    public void testInit_String_String() {
        System.out.println("Init");
        String osName = "";
        String time = "";
        Anonymous instance = new Anonymous();
        InitResponse expResult = null;
        InitResponse result = instance.Init(osName, time);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

}
