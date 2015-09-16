
		for (i=0; i<3; i++)
		{
		    R1 = new MsgIn.Body.List2.Sublist1.Record1();
			R1.setField1((byte) (i+4));
			L1.addElement(R1);
		}

		// Second sublist should be 7 elements long
		for (i=0; i<7; i++)
		{
			R1 = new MsgIn.Body.List2.Sublist1.Record1();
			R1.setField1((byte) (i+8));
			L2.addElement(R1);
		}

		// Add both sublists to the main list
		m_MsgIn1.getBody().getList2().addElement(L1);
		m_MsgIn1.getBody().getList2().addElement(L2);
		m_MsgIn2.getBody().setList2( list ); 
           
		   assertEquals(m_MsgIn2.getBody().getList2().getNumberOfElements(),i);
		   L1 = new MsgIn.Body.List2.Sublist1();
		   m_MsgIn2.getBody().getList2().addElement(L1);

		   for (j=0;j<4;j++) {
			  assertEquals(m_MsgIn2.getBody().getList2().getElement(i).getNumberOfElements(), j);
			  R1 = new MsgIn.Body.List2.Sublist1.Record1();
			  m_MsgIn2.getBody().getList2().getElement(i).addElement(R1);           
			   }
			}
			for (i=4;i>0;i--) {
				assertEquals(m_MsgIn2.getBody().getList2().getNumberOfElements(), i);
				m_MsgIn2.getBody().getList2().deleteLastElement();
			}

		for (i=0;i<4;i++) {
			L1 = new MsgIn.Body.List2.Sublist1();
			m_MsgIn1.getBody().getList2().addElement(L1);

			for (j=0; j<4; j++) {
			  R1 = new MsgIn.Body.List2.Sublist1.Record1();
			  m_MsgIn1.getBody().getList2().getElement(i).addElement(R1);
			  m_MsgIn1.getBody().getList2().getElement(i).getElement(j).setField1( (byte) ((i*4)+j) );
			}
		}

		// Delete a sampling of elemments from the top list and the sublists...
		m_MsgIn1.getBody().getList2().deleteElement(0);
		m_MsgIn1.getBody().getList2().getElement(0).deleteElement(0);
		m_MsgIn1.getBody().getList2().getElement(1).deleteElement(1);
		m_MsgIn1.getBody().getList2().getElement(2).deleteElement(2);

		// Verify...
		assertEquals(m_MsgIn1.getBody().getList2().getNumberOfElements(), 3);
		for (i=0;i<3;i++) {

			assertEquals(m_MsgIn1.getBody().getList2().getElement(i).getNumberOfElements(), 3);

			for (j=0; j<3; j++) {
				int target_value = (i>j ? ((i+1)*4)+j :  ((i+1)*4)+j+1); 
				 assertEquals(m_MsgIn1.getBody().getList2().getElement(i).getElement(j).getField1(), target_value);
			}
		}