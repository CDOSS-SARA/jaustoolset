/***********           LICENSE HEADER   *******************************
JAUS Tool Set
Copyright (c)  2010, United States Government
All rights reserved.

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions are met:

       Redistributions of source code must retain the above copyright notice, 
this list of conditions and the following disclaimer.

       Redistributions in binary form must reproduce the above copyright 
notice, this list of conditions and the following disclaimer in the 
documentation and/or other materials provided with the distribution.

       Neither the name of the United States Government nor the names of 
its contributors may be used to endorse or promote products derived from 
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
POSSIBILITY OF SUCH DAMAGE.
*********************  END OF LICENSE ***********************************/

#include <iostream>

#include "urn_org_jts_test_Record2_1_0/Messages/MessageSet.h"

#include "cppunit/TestCaller.h"
#include "cppunit/TestCaller.h"
#include "cppunit/ui/text/TestRunner.h"
#include "cppunit/TestSuite.h"

using namespace urn_org_jts_test_Record2_1_0;

#define OUT_0  std::cout
#define OUT_1  if (bVerbose<=2) std::cout 
#define OUT_2  if (bVerbose<=1) std::cout

class JTSBody2MessageTest : public CppUnit::TestFixture {
             
private:
  MsgIn m_MsgIn1,m_MsgIn2;
  int bVerbose;
  
public:
  JTSBody2MessageTest() {
     bVerbose=0;
  }     
       
  void setUp()
  {
  }

  void tearDown() 
  {
  }

  void testConstructionDefaults()
  {
    OUT_1 << std::endl << "  [executing test (testConstructionDefaults)] " << std::endl;

    OUT_2 << "     --- verifying MsgIn constructs with correct default MessageID" << std::endl;
    CPPUNIT_ASSERT( m_MsgIn1.getHeader()->getHeaderRec()->getMessageID() == 1 );
    CPPUNIT_ASSERT( m_MsgIn2.getHeader()->getHeaderRec()->getMessageID() == 1 );

  }
  
  void testSetGetOperations()
  {
    OUT_1 << std::endl << "  [executing test (testSetGetOperations)(TP_3.3.5.1)] " << std::endl;
    
    OUT_2 << "     --- verifying setMessageID/getMessageID reciprocity" << std::endl;
    m_MsgIn1.getHeader()->getHeaderRec()->setMessageID(5);
    CPPUNIT_ASSERT( m_MsgIn1.getHeader()->getHeaderRec()->getMessageID() == 5 );
    m_MsgIn1.getHeader()->getHeaderRec()->setMessageID(1);
    CPPUNIT_ASSERT( m_MsgIn1.getHeader()->getHeaderRec()->getMessageID() == 1 );

    OUT_2 << "     --- verifying setField1/getField1 reciprocity" << std::endl;    
    m_MsgIn1.getBody2()->getRecord2()->setField1(126);
    m_MsgIn2.getBody2()->getRecord2()->setField1(-127);
    m_MsgIn1.getBody2()->getRecord2()->setField2(-40000);
    m_MsgIn2.getBody2()->getRecord2()->setField2(43210);
    m_MsgIn1.getBody2()->getRecord2()->setField3(0.5);
    m_MsgIn2.getBody2()->getRecord2()->setField3(-32.125);
    m_MsgIn1.getBody2()->getRecord2()->setField4(255);
    m_MsgIn2.getBody2()->getRecord2()->setField4(0);
        
    CPPUNIT_ASSERT( m_MsgIn1.getBody2()->getRecord2()->getField1() == 126);
    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField1() == -127);    
    CPPUNIT_ASSERT( m_MsgIn1.getBody2()->getRecord2()->getField2() == -40000);
    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField2() == 43210);    
    CPPUNIT_ASSERT( m_MsgIn1.getBody2()->getRecord2()->getField3() == 0.5);
    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField3() == -32.125);    
    CPPUNIT_ASSERT( m_MsgIn1.getBody2()->getRecord2()->getField4() == 255);
    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField4() == 0);    
    
    OUT_1 <<  "  [completed test (testSetGetOperations)] " << std::endl;
             
  }

  void testEncodeToSpec()
  {
    unsigned char buff[1024];
    int i;
       
    m_MsgIn1.getHeader()->getHeaderRec()->setMessageID(256);
    m_MsgIn1.getBody2()->getRecord2()->setField1(2);
    m_MsgIn1.getBody2()->getRecord2()->setField2(100992003);  //6.59782e-33
    m_MsgIn1.getBody2()->getRecord2()->setField3(0.00000000000000000000000000000000659782);
    m_MsgIn1.getBody2()->getRecord2()->setField4(11);
    

    OUT_2 << "     --- verifying message level encode is AS-5684 compliant" << std::endl;
    m_MsgIn1.encode(buff);
    
    for (i=0;i<m_MsgIn1.getSize();i++)
       CPPUNIT_ASSERT( buff[i]==i );

    OUT_1 << "  [completed test (testEncodeToSpec)] " << std::endl;
       
  }
  
  void testEncodeDecodeOperations()
  {
    unsigned char buff[1024];
    int i;
    
    for (i=0;i<1024;i++)
       buff[i] = ((4101*i)+65543) % 256;
    
    OUT_1 << std::endl << "  [executing test (testEncodeDecodeOperations)(TP_3.3.5.3)] " << std::endl;
    
    OUT_2 << "     --- verifying message level encode/decode reciprocity" << std::endl;

    m_MsgIn1.getHeader()->getHeaderRec()->setMessageID(41);
    m_MsgIn1.getBody2()->getRecord2()->setField1(24);
    m_MsgIn1.getBody2()->getRecord2()->setField2(25);
    m_MsgIn1.getBody2()->getRecord2()->setField3(26);
    m_MsgIn1.getBody2()->getRecord2()->setField4(27);


    m_MsgIn2.getHeader()->getHeaderRec()->setMessageID(127);
    m_MsgIn2.getBody2()->getRecord2()->setField1(127);
    m_MsgIn2.getBody2()->getRecord2()->setField2(127);
    m_MsgIn2.getBody2()->getRecord2()->setField3(127);
    m_MsgIn2.getBody2()->getRecord2()->setField4(127);
    
    m_MsgIn1.encode(buff);
    m_MsgIn2.decode(buff);
    
    CPPUNIT_ASSERT( m_MsgIn2.getHeader()->getHeaderRec()->getMessageID() == 41);
    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField1()==24);
    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField2()==25);
    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField3()==26);
    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField4()==27);
    
    OUT_2 << "     --- verifying header level encode/decode reciprocity" << std::endl;
    
    m_MsgIn2.getHeader()->getHeaderRec()->setMessageID(0);
    m_MsgIn1.getHeader()->encode(buff);
    m_MsgIn2.getHeader()->decode(buff);
    CPPUNIT_ASSERT( m_MsgIn2.getHeader()->getHeaderRec()->getMessageID() == 41);

    m_MsgIn2.getHeader()->getHeaderRec()->setMessageID(0);
    m_MsgIn1.getHeader()->getHeaderRec()->encode(buff);
    m_MsgIn2.getHeader()->getHeaderRec()->decode(buff);
    CPPUNIT_ASSERT( m_MsgIn2.getHeader()->getHeaderRec()->getMessageID() == 41);

    OUT_2 << "     --- verifying record level encode/decode reciprocity" << std::endl;

    m_MsgIn2.getBody2()->getRecord2()->setField1(0);
    m_MsgIn2.getBody2()->getRecord2()->setField2(0);
    m_MsgIn2.getBody2()->getRecord2()->setField3(0);
    m_MsgIn2.getBody2()->getRecord2()->setField4(0);
        
    m_MsgIn1.getBody2()->encode(buff);
    m_MsgIn2.getBody2()->decode(buff);

    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField1()==24);
    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField2()==25);
    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField3()==26);
    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField4()==27);

    m_MsgIn2.getBody2()->getRecord2()->setField1(0);
    m_MsgIn2.getBody2()->getRecord2()->setField2(0);
    m_MsgIn2.getBody2()->getRecord2()->setField3(0);
    m_MsgIn2.getBody2()->getRecord2()->setField4(0);
        
    m_MsgIn1.getBody2()->getRecord2()->encode(buff);
    m_MsgIn2.getBody2()->getRecord2()->decode(buff);

    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField1()==24);
    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField2()==25);
    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField3()==26);
    CPPUNIT_ASSERT( m_MsgIn2.getBody2()->getRecord2()->getField4()==27);
            
    OUT_1 << "  [completed test (testEncodeDecodeOperations)] " << std::endl;
       
  }

  void testEquality()
  {
    OUT_1 << std::endl << "  [executing test (testEquality)] " << std::endl;
    OUT_2 << "     --- verifying message equality operator" << std::endl;    
    CPPUNIT_ASSERT( m_MsgIn1 == m_MsgIn2 );
    OUT_1 << "  [completed test (testEquality)] " << std::endl;
    
  }
  
  void testInequality()
  {
    OUT_1 << std::endl << "  [executing test (testInequality)] " << std::endl;
    OUT_2 << "     --- verifying message inequality operator" << std::endl;    
       
    CPPUNIT_ASSERT( !(m_MsgIn1 != m_MsgIn2) );
    OUT_1 << "  [completed test (testInequality)] " << std::endl;
    
  }

  static CppUnit::Test *suite()
  {
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "JTSBody2MessageTest" );
    
    suiteOfTests->addTest( new CppUnit::TestCaller<JTSBody2MessageTest>( 
                                   "testConstructionDefaults", 
                                   &JTSBody2MessageTest::testConstructionDefaults ) );
                                   
    suiteOfTests->addTest( new CppUnit::TestCaller<JTSBody2MessageTest>( 
                                   "testSetGetOperations (TP_3.3.5.1)", 
                                   &JTSBody2MessageTest::testSetGetOperations ) );
                                   
    suiteOfTests->addTest( new CppUnit::TestCaller<JTSBody2MessageTest>( 
                                   "testEncodeToSpec (TP_3.3.5.2)", 
                                   &JTSBody2MessageTest::testEncodeToSpec ) );
                                   
    suiteOfTests->addTest( new CppUnit::TestCaller<JTSBody2MessageTest>( 
                                   "testEncodeDecodeOperations (TP_3.3.5.3)", 
                                   &JTSBody2MessageTest::testEncodeDecodeOperations ) );                                   
                                                                      
    suiteOfTests->addTest( new CppUnit::TestCaller<JTSBody2MessageTest>( 
                                   "testEquality", 
                                   &JTSBody2MessageTest::testEquality ) );
                                   
    suiteOfTests->addTest( new CppUnit::TestCaller<JTSBody2MessageTest>(
                                   "testInequality",
                                   &JTSBody2MessageTest::testInequality ) );
    return suiteOfTests;
  }

};


int main( int ac, char **av )
{
  CppUnit::TextUi::TestRunner runner;
  runner.addTest( JTSBody2MessageTest::suite() );
  
  OUT_0 << std::endl << "------------------------------------------------" << std::endl;
  OUT_0 << "Executing suite JTSBody2MessageTest" << std::endl;
  runner.run();
  OUT_0 << std::endl << "Completed suite JTSBody2MessageTest" << std::endl;
  OUT_0 << "------------------------------------------------" << std::endl;  
}

