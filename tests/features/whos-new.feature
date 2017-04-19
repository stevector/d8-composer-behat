Feature: "Who's New" Block
  In order to track newly created users
  As an administrator
  I want a listing of the newest user accounts on the homepage.

  @api
  Scenario: New user appears in list (poor abstraction)
    Given I am logged in as an "administrator"
    And I visit "admin/people/create"
    And I fill in "edit-mail" with "testing@example.com"
    And I fill in "edit-name" with "Test Account 1"
    And I fill in "edit-pass-pass1" with "some random pass"
    And I fill in "edit-pass-pass2" with "some random pass"
    And I press "Create new account"
    When I visit "/"
    Then I should see "Test Account 1" in the "#block-views-block-who-s-new-block-1" element
