package com.company;

/**
 * Created by Adil on 03.10.2018.
 */
public class MyDate
{
    private int day;
    private String month;
    private int year;

    public MyDate()
    {
        this(1, "January", 2000);
    }

    public MyDate(int day, String month, int year)
    {
        setDate(day, month, year);
    }

    public MyDate(int day, int monthNumber, int year)
    {
        setDate(day, monthNumber, year);
    }

    public MyDate(MyDate original)
    {
        if (original == null)
        {
            System.out.println("Error: null Date object");
            System.exit(0);
        }
        setDate(original.day, original.month, original.year);
    }

    public int getDay()
    {
        return day;
    }

    public int getMonth()
    {
        switch(month.toLowerCase())
        {
            case "january": return 1;
            case "february": return 2;
            case "march": return 3;
            case "april": return 4;
            case "may": return 5;
            case "june": return 6;
            case "july": return 7;
            case "august": return 8;
            case "september": return 9;
            case "october": return 10;
            case "november": return 11;
            case "december": return 12;
            default: return 0;
        }
    }

    public int getYear()
    {
        return year;
    }

    public void setDay(int day)
    {
        if (!dateOK(day, month, year))
        {
            System.out.println("Error: illegal day.");
            System.exit(0);
        }
        this.day = day;
    }

    public void setMonth(String month)
    {
        if (!dateOK(day, month, year))
        {
            System.out.println("Error: illegal month.");
            System.exit(0);
        }
        this.month = month;
    }

    public void setMonth(int monthNumber)
    {
        if (!dateOK(day, monthNumber, year))
        {
            System.out.println("Error: illegal month number.");
            System.exit(0);
        }
        this.month = monthString(monthNumber);
    }

    public void setYear(int year)
    {
        if (!dateOK(day, month, year))
        {
            System.out.println("Error: illegal year.");
            System.exit(0);
        }
        this.year = year;
    }

    public void setDate(int day, String month, int year)
    {
        if (!dateOK(day, month, year))
        {
            System.out.println("Error: illegal date.");
            System.exit(0);
        }
        this.day = day;
        this.month = month;
        this.year = year;
    }

    public void setDate(int day, int monthNumber, int year)
    {
        if (!dateOK(day, monthNumber, year))
        {
            System.out.println("Error: illegal date.");
            System.exit(0);
        }
        this.day = day;
        this.month = monthString(monthNumber);
        this.year = year;
    }

    public boolean equals(MyDate otherDate)
    {
        return (day == otherDate.day
                && getMonth() == otherDate.getMonth()
                && year == otherDate.year);
    }

    public String toString()
    {
        return getMonth() + "." + day + "." + year;
    }

    public boolean precedes(MyDate otherDate)
    {
        return (year < otherDate.year)
                || (year == otherDate.year
                && getMonth() < otherDate.getMonth())
                || (year == otherDate.year
                && getMonth() == otherDate.getMonth()
                && day < otherDate.day);
    }

    private static boolean isLeapYear(int year)
    {
        return (year % 4 == 0 && year % 100 !=0)
                || (year % 400 == 0);
    }

    private static String monthString(int monthNumber)
    {
        switch (monthNumber)
        {
            case 1: return "January";
            case 2: return "February";
            case 3: return "March";
            case 4: return "April";
            case 5: return "May";
            case 6: return "June";
            case 7: return "July";
            case 8: return "August";
            case 9: return "September";
            case 10: return "October";
            case 11: return "November";
            case 12: return "December";
            default : return "Error: illegal month number";
        }
    }

    private static boolean dateOK(int day, String month, int year)
    {
        if (year < 1900 || year > 9999)
            return false;
        switch (month.toLowerCase())
        {
            case "january":
            case "march":
            case "may":
            case "july":
            case "august":
            case "october":
            case "december": return (day >= 1 && day <= 31);
            case "april":
            case "june":
            case "september":
            case "november": return (day >= 1 && day <= 30);
            case "february":
                if (isLeapYear(year))
                    return (day >= 1 && day <= 29);
                return (day >= 1 && day <= 28);
            default: return false;
        }
    }

    private static boolean dateOK(int day, int monthNumber, int year)
    {
        String monthString = monthString(monthNumber);
        return dateOK(day, monthString, year);
    }
}
