<#
.SYNOPSIS 
Reads a text file containing whole numbers. Prints out a sum for each line. For even lines the sum is made from even numbers, for odd lines, it is made from odd numbers

.DESCRIPTION
This scripts calculates sums of even and uneven numbers

.PARAMETER Path
Path of the file that will be read. Mandatory.

.PARAMETER Separator
Optional parameter describing the separator between the numbers in the text file

.OUTPUTS
An array of integers, with the length equaling the lines in the text file. If a line in the file contains no even or odd numbers, the sum will be 0.

.EXAMPLE
.\bead3.ps1 -Path .\test.txt -Separator ',' -Verbose

.EXAMPLE
.\bead3.ps1 -Path .\test2.txt

.EXAMPLE
.\bead3.ps1 .\test3.txt

.NOTES
Author: Koller David Daniel
Neptun ID: IDJJQ2
#>

[CmdletBinding()]
Param(
    [string] [Parameter(Mandatory)] $Path,
	[char] $Separator = ' '
)
Write-Verbose "The path is: $Path and the separator is $Separator"
$lineIsEven = $true
(Get-Content -Path $Path).ForEach(
{
	$lineIsEven = !$lineIsEven
	Write-Verbose "this line's parity: $([int]$lineIsEven)"
	$sum = 0
	$_.Split($Separator).ForEach(
	{
		$x = [int]$_
		if (($x % 2 -eq 0) -eq $lineIsEven)
		{
			Write-Verbose "The number $x is added to the sum"
			$sum += $x
		}
	})
	write $sum
})