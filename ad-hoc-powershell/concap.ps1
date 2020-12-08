Param(
    [parameter(mandatory=$true)][string]$concap_file
)
if(Test-Path -Path $concap_file)
{
    $incre = 0
    $concap = Import-Csv -Path ./concap.csv
    foreach($line in $concap) {Write-Host $line.CountryName; $incre++ }
    
    Write-Host "There are" $incre "records in concap.csv" 
}
else {
    Write-Host $concap_file "does not exist!"
}