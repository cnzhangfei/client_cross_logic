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
public class InitResponseIT {

    public InitResponseIT() {
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
     * Test of getVirtualId method, of class InitResponse.
     */
    @Test
    public void testGetVirtualId() {
        System.out.println("getVirtualId");
        InitResponse instance = new InitResponse();
        String expResult = null;
        String result = instance.getVirtualId();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of setVirtualId method, of class InitResponse.
     */
    @Test
    public void testSetVirtualId() {
        System.out.println("setVirtualId");
        String virtualId = "";
        InitResponse instance = new InitResponse();
        instance.setVirtualId(virtualId);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

}
