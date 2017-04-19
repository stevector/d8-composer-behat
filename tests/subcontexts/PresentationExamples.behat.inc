<?php

/**
 * Contains \FooFoo.
 */

use Behat\Behat\Hook\Scope\BeforeScenarioScope;
use Behat\Behat\Tester\Exception\PendingException;
use Drupal\DrupalExtension\Context\DrupalSubContextBase;
use Drupal\DrupalExtension\Context\DrupalSubContextInterface;

/**
 * Example subcontext.
 */
class PresentationExamples extends DrupalSubContextBase implements DrupalSubContextInterface {

  /**
   * @var \Drupal\DrupalExtension\Context\DrupalContext
   */
  protected $drupalContext;

  /**
   * @var \Drupal\DrupalExtension\Context\MinkContext
   */
  protected $minkContext;

  /**
   * @BeforeScenario
   */
  public function gatherContexts(BeforeScenarioScope $scope) {
    $environment = $scope->getEnvironment();

    $this->drupalContext = $environment->getContext('Drupal\DrupalExtension\Context\DrupalContext');
    $this->minkContext = $environment->getContext('Drupal\DrupalExtension\Context\MinkContext');
  }

  /**
   * @Given a new user account has recently been created
   */
  public function aNewUserAccountHasRecentlyBeenCreated()
  {
    $this->newly_created_username = rand();
    $user = new StdClass();
    $user->name = $this->newly_created_username;
    $user->mail = $user->name . '@example.com';
    $user->pass = rand();

    $this->drupalContext->userCreate($user);
  }

  /**
   * @Then I should see the username for the new account in the Who's New Block.
   */
  public function iShouldSeeTheUsernameForTheNewAccountInTheWhosNewBlock()
  {
    $this->minkContext->assertElementContainsText("#block-views-block-who-s-new-block-1", $this->newly_created_username);
  }
}

