/*
 * Sequence.java
 *
 * This code has been auto-updated by JTS after it has been auto-generated by umlc
 * Created on Wed Oct 05 10:31:03 EDT 2011
 */

package com.u2d.generated;


import com.u2d.model.*;
import com.u2d.app.PersistenceMechanism;
import com.u2d.type.*;
import com.u2d.type.atom.*;
import com.u2d.type.composite.*;
import com.u2d.list.RelationalList;
import com.u2d.reflection.Fld;
import javax.persistence.Entity;
import com.u2d.reflection.IdxFld;


@Entity
public  class Sequence extends ComplexField {

    
    /** Creates a new instance of Sequence */
    public Sequence() {
    }
    public Title title() { 
        StringBuffer text = new StringBuffer();
        text.append(name.title() + " [Sequence]");
        return new Title(text.toString());
    }    
    


    // ******    name   ******
    private final StringEO name = new StringEO();
    public StringEO getName() { return name;}

    // ******    optional   ******
    private final BooleanEO optional = new BooleanEO();
    public BooleanEO getOptional() { return optional;}

    // ******    interpretation   ******
    private final StringEO interpretation = new StringEO();
    public StringEO getInterpretation() { return interpretation;}

   


 
    // *********  complexFields ******
    private final RelationalList complexFields = new RelationalList(ComplexField.class);
    public static final Class complexFieldsType = ComplexField.class;
    public static final int complexFieldsRelationType = PersistenceMechanism.MANY_TO_MANY;    
    public static final boolean complexFieldsRelationIsInverse = false;
    @IdxFld(ordered=true)
    public RelationalList getComplexFields() {
    return complexFields; 
    } 
 
 
/************** Uncomment the following as needed *****************************/
      public static String[] fieldOrder  = {"name", "optional", "complexFields", "interpretation", "referencingElements"};
public static String[] readOnly  = {"referencingElements"};
// ******    referencingElements   ******
   private final StringEO referencingElements = new StringEO("{Headers, Bodies, Footers, Lists, Sequences, Variants}");
   public StringEO getReferencingElements() { return referencingElements;}

      ;
//    public static String[] tabViews          = {"fieldname1", "fieldname2"};

      ;
//    public static String[] flattenIntoParent = {"fieldname1", "fieldname2"};

      ;
//    public static String[] identities = {"fieldname1", "fieldname2"};

//    public static String pluralName() { return "Sequences"; }
      /* Specify a color to represnt this class */
//    public static Color colorCode = new Color(0x2332);

      /* Use a different Icon for each instance. Change photoFieldName. */
//    private transient PhotoIconAssistant assistant = 
//                        new PhotoIconAssistant(this, photoFieldname);
//    public Icon iconLg() { return assistant.iconLg(); }
//    public Icon iconSm() { return assistant.iconSm(); }


      /* Specify the default search field for this class */
//    public static String defaultSearchPath = "";


      /* Specify a custom view for this class. 
//    public EView getMainView()
//    {
//       return new CustomSequenceView(this);
//    }
/**********************/
/**@Cmd place holder**/        
}